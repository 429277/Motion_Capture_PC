#include "GLViewerPositionalTracking.hpp"
#include "shader.hpp"

void printPositionalTracking(std::string msg_prefix, sl::ERROR_CODE err_code, std::string msg_suffix) {
    cout <<"[Sample]";
    if (err_code != sl::ERROR_CODE::SUCCESS)
        cout << "[Error] ";
    else
        cout<<" ";
    cout << msg_prefix << " ";
    if (err_code != sl::ERROR_CODE::SUCCESS) {
        cout << " | " << toString(err_code) << " : ";
        cout << toVerbose(err_code);
    }
    if (!msg_suffix.empty())
        cout << " " << msg_suffix;
    cout << endl;
}

using namespace sl;

GLViewerPositionalTracking* currentInstance_ = nullptr;

GLViewerPositionalTracking::GLViewerPositionalTracking() : available(false) {
    currentInstance_ = this;
    mouseButton_[0] = mouseButton_[1] = mouseButton_[2] = false;
    clearInputs();
    previousMouseMotion_[0] = previousMouseMotion_[1] = 0;
}

GLViewerPositionalTracking::~GLViewerPositionalTracking() {}

void GLViewerPositionalTracking::exit() {
    available = false;    
}

bool GLViewerPositionalTracking::isAvailable() {
    if(available)
        glutMainLoopEvent();
    return available;
}

void CloseFuncPositionalTracking(void) { if(currentInstance_) currentInstance_->exit(); }

void fillZED(int nb_tri, float *vertices, int *triangles, sl::float3 color, Simple3DObjectPositionalTracking *zed_camera) {
    for (int p = 0; p < nb_tri * 3; p = p + 3) {
        int index = triangles[p] - 1;
        zed_camera->addPoint(vertices[index * 3], vertices[index * 3 + 1], vertices[index * 3 + 2], color.r, color.g, color.b);
        index = triangles[p + 1] - 1;
        zed_camera->addPoint(vertices[index * 3], vertices[index * 3 + 1], vertices[index * 3 + 2], color.r, color.g, color.b);
        index = triangles[p + 2] - 1;
        zed_camera->addPoint(vertices[index * 3], vertices[index * 3 + 1], vertices[index * 3 + 2], color.r, color.g, color.b);
    }
}

void addVert(Simple3DObjectPositionalTracking &obj, float i_f, float limit, sl::float3 &clr) {
    auto p1 = sl::float3(i_f, 0, -limit);
    auto p2 = sl::float3(i_f, 0, limit);
    auto p3 = sl::float3(-limit, 0, i_f);
    auto p4 = sl::float3(limit, 0, i_f);

    obj.addLine(p1, p2, clr);
    obj.addLine(p3, p4, clr);
}

void GLViewerPositionalTracking::init(int argc, char **argv, sl::MODEL camera_model) {
    if (glutGet(GLUT_INIT_STATE) != 1) {
        glutInit(&argc, argv);
    }

    int wnd_w = glutGet(GLUT_SCREEN_WIDTH);
    int wnd_h = glutGet(GLUT_SCREEN_HEIGHT) *0.9;
    glutInitWindowSize(wnd_w*0.9, wnd_h*0.9);
    glutInitWindowPosition(wnd_w*0.05, wnd_h*0.05);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("ZED Positional Tracking");

    GLenum err = glewInit();
    if (GLEW_OK != err)
        printPositionalTracking("ERROR: glewInit failed: " + std::string((char*)glewGetErrorString(err)));

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    
    // Compile and create the shader
    mainShader.it.set(VERTEX_SHADER, FRAGMENT_SHADER);
    mainShader.MVP_Mat = glGetUniformLocation(mainShader.it.getProgramId(), "u_mvpMatrix");
    
    shaderLine.it.set(VERTEX_SHADER, FRAGMENT_SHADER);
    shaderLine.MVP_Mat = glGetUniformLocation(shaderLine.it.getProgramId(), "u_mvpMatrix");

    // Create the camera
    camera_.setPosition(sl::Translation(0.3, 3.3, -3.3));
    camera_.setDirection(sl::Translation(0, 0, -4), sl::Translation(0, 1, 0));
    sl::float3 euler(-50, 180, 0);
    sl::Rotation cam_rot;
    cam_rot.setEulerAngles(euler, 0);
    camera_.setRotation(sl::Rotation(cam_rot));
    
    floor_grid = Simple3DObjectPositionalTracking(sl::Translation(0, 0, 0), true);
    floor_grid.setDrawingType(GL_LINES);

    float limit = 20.f;

    sl::float3 clr1(218, 223, 225);
    clr1 /= 255.f;
    sl::float3 clr2(108, 122, 137);
    clr2 /= 255.f;
    for(int i = (int) (limit * -5); i <= (int) (limit * 5); i++) {
        float i_f = i / 5.f;
        if((i % 5) == 0)
            addVert(floor_grid, i_f, limit, clr2);
        else
            addVert(floor_grid, i_f, limit, clr1);
    }

    floor_grid.pushToGPU();

    bckgrnd_clr = sl::float3(223, 230, 233);
    bckgrnd_clr /= 255.f;

    zedPath.setDrawingType(GL_LINE_STRIP);

    Model3D *model = nullptr;
    switch(camera_model){
        case sl::MODEL::ZED:
            model = new Model3D_ZED;
            break;
        case sl::MODEL::ZED_M:
        case sl::MODEL::ZED_XM :
            model = new Model3D_ZED_M;
            break;
        case sl::MODEL::ZED2:
        case sl::MODEL::ZED2i:
        case sl::MODEL::ZED_X:
            model = new Model3D_ZED2;
            break;
        // case sl::MODEL::ZED_X:
        //     model = new Model3D_ZED_X;
        //     break;
    };
    if(model){
        for (auto it: model->part)
            fillZED(it.nb_triangles, model->vertices, it.triangles, it.color, &zedModel);
        delete model;
    }
    zedModel.pushToGPU();

    updateZEDposition = false;

    // Map glut function on this class methods
    glutDisplayFunc(GLViewerPositionalTracking::drawCallback);
    glutMouseFunc(GLViewerPositionalTracking::mouseButtonCallback);
    glutMotionFunc(GLViewerPositionalTracking::mouseMotionCallback);
    glutReshapeFunc(GLViewerPositionalTracking::reshapeCallback);
    glutKeyboardFunc(GLViewerPositionalTracking::keyPressedCallback);
    glutKeyboardUpFunc(GLViewerPositionalTracking::keyReleasedCallback);
    glutCloseFunc(CloseFuncPositionalTracking);
    
    available = true;
}

void GLViewerPositionalTracking::render() {
    if (available) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(bckgrnd_clr.r, bckgrnd_clr.g, bckgrnd_clr.b, 1.f);
        update();
        draw();
        printText();
        glutSwapBuffers();
        glutPostRedisplay();
    }
}

void GLViewerPositionalTracking::update() {
    //Quit the software
    if (keyStates_['q'] == KEY_STATE::UP || keyStates_['Q'] == KEY_STATE::UP || keyStates_[27] == KEY_STATE::UP) {
        currentInstance_->exit();
        return;
    }


    //Reset the position to "origin"
    if (keyStates_['r'] == KEY_STATE::UP)
    {
        camera_.setPosition(sl::Translation(0.3, 3.3, -3.3));
        camera_.setDirection(sl::Translation(0, 0, -4), sl::Translation(0, 1, 0));
        sl::float3 euler(-50, 180, 0);
        sl::Rotation cam_rot;
        cam_rot.setEulerAngles(euler, 0);
        camera_.setRotation(sl::Rotation(cam_rot));

    }
    // Rotate camera with mouse
    if (mouseButton_[MOUSE_BUTTON::LEFT]) {
        camera_.rotate(sl::Rotation((float) mouseMotion_[1] * MOUSE_R_SENSITIVITY, camera_.getRight()));
        camera_.rotate(sl::Rotation((float) mouseMotion_[0] * MOUSE_R_SENSITIVITY, camera_.getVertical() * -1.f));
    }

    // Translate camera with mouse
    if (mouseButton_[MOUSE_BUTTON::RIGHT]) {
        camera_.translate(camera_.getUp() * (float) mouseMotion_[1] * MOUSE_T_SENSITIVITY);
        camera_.translate(camera_.getRight() * (float) mouseMotion_[0] * MOUSE_T_SENSITIVITY);
    }

    // Zoom in with mouse wheel (translate in projZ)
    if (mouseWheelPosition_ != 0)
        camera_.translate(-1.0*camera_.getForward() * mouseWheelPosition_ * MOUSE_WHEEL_SENSITIVITY);

    
    // update 
    camera_.update();
    clearInputs();
    mtx.lock();
    if (updateZEDposition) {
        zedPath.clear();
        sl::float3 clr(0.1f, 0.5f, 0.9f);
        for (unsigned int i = 1; i < vecPath.size(); i++) {
            float fade = (i*1.f) / vecPath.size();
            sl::float3 new_color = clr * fade;
            zedPath.addPoint(vecPath[i], new_color);
        }
        zedPath.pushToGPU();
        updateZEDposition = false;
    }
    mtx.unlock();
}

void GLViewerPositionalTracking::draw() {
    const sl::Transform vpMatrix = camera_.getViewProjectionMatrix();

    // Simple 3D shader for simple 3D objects
    glUseProgram(shaderLine.it.getProgramId());
    glUniformMatrix4fv(shaderLine.MVP_Mat, 1, GL_TRUE, vpMatrix.m);
    glLineWidth(1.f);
    floor_grid.draw();
    glUseProgram(0);

    glUseProgram(mainShader.it.getProgramId());
    glUniformMatrix4fv(mainShader.MVP_Mat, 1, GL_TRUE, vpMatrix.m);

    glLineWidth(2.f);
    zedPath.draw();

    // Move the ZED 3D model to correct position
    glUniformMatrix4fv(mainShader.MVP_Mat, 1, GL_FALSE, (sl::Transform::transpose(zedModel.getModelMatrix()) *  sl::Transform::transpose(vpMatrix)).m);
    zedModel.draw();

    glUseProgram(0);
}

void GLViewerPositionalTracking::updateData(sl::Transform zed_rt, std::string str_t, std::string str_r, sl::PositionalTrackingStatus state) {
    mtx.lock();
    vecPath.push_back(zed_rt.getTranslation());
    zedModel.setRT(zed_rt);
    updateZEDposition = true;
    txtT = str_t;
    txtR = str_r;
    trackState = state;
    mtx.unlock();
}

static void safe_glutBitmapString(void *font, const char *str) {
    for (size_t x = 0; x < strlen(str); ++x)
        glutBitmapCharacter(font, str[x]);
}

void GLViewerPositionalTracking::printText() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    int w_wnd = glutGet(GLUT_WINDOW_WIDTH);
    int h_wnd = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0, w_wnd, 0, h_wnd, -1.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    int start_w = 20;
    int start_h = h_wnd - 40;

    float dark_clr = 0.12f;
    std::string odom_status = "POSITIONAL TRACKING STATUS: ";
    
    glColor3f(dark_clr, dark_clr, dark_clr);
    glRasterPos2i(start_w, start_h);
    safe_glutBitmapString(GLUT_BITMAP_HELVETICA_18, odom_status.c_str());

    (trackState.tracking_fusion_status != sl::POSITIONAL_TRACKING_FUSION_STATUS::UNAVAILABLE) ? glColor3f(0.2f, 0.65f, 0.2f) : glColor3f(0.85f, 0.2f, 0.2f);
    std::string track_str = (sl::toString(trackState.tracking_fusion_status).c_str());
    glRasterPos2i(start_w + 300, start_h);
    safe_glutBitmapString(GLUT_BITMAP_HELVETICA_18, track_str.c_str());
    
    glColor3f(dark_clr, dark_clr, dark_clr);
    glRasterPos2i(start_w, start_h - 20);
    safe_glutBitmapString(GLUT_BITMAP_HELVETICA_18, "Translation (m) :");

    glColor3f(0.4980f, 0.5490f, 0.5529f);
    glRasterPos2i(155, start_h - 20);

    safe_glutBitmapString(GLUT_BITMAP_HELVETICA_18, txtT.c_str());

    glColor3f(dark_clr, dark_clr, dark_clr);
    glRasterPos2i(start_w, start_h - 40);
    safe_glutBitmapString(GLUT_BITMAP_HELVETICA_18, "Rotation   (rad) :");

    glColor3f(0.4980f, 0.5490f, 0.5529f);
    glRasterPos2i(155, start_h - 40);
    safe_glutBitmapString(GLUT_BITMAP_HELVETICA_18, txtR.c_str());

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void GLViewerPositionalTracking::clearInputs() {
    mouseMotion_[0] = mouseMotion_[1] = 0;
    mouseWheelPosition_ = 0;
    for (unsigned int i = 0; i < 256; ++i)
        if (keyStates_[i] != KEY_STATE::DOWN)
            keyStates_[i] = KEY_STATE::FREE;
}

void GLViewerPositionalTracking::drawCallback() {
    currentInstance_->render();
}

void GLViewerPositionalTracking::mouseButtonCallback(int button, int state, int x, int y) {
    if (button < 5) {
        if (button < 3) {
            currentInstance_->mouseButton_[button] = state == GLUT_DOWN;
        } else {
            currentInstance_->mouseWheelPosition_ += button == MOUSE_BUTTON::WHEEL_UP ? 1 : -1;
        }
        currentInstance_->mouseCurrentPosition_[0] = x;
        currentInstance_->mouseCurrentPosition_[1] = y;
        currentInstance_->previousMouseMotion_[0] = x;
        currentInstance_->previousMouseMotion_[1] = y;
    }
}

void GLViewerPositionalTracking::mouseMotionCallback(int x, int y) {
    currentInstance_->mouseMotion_[0] = x - currentInstance_->previousMouseMotion_[0];
    currentInstance_->mouseMotion_[1] = y - currentInstance_->previousMouseMotion_[1];
    currentInstance_->previousMouseMotion_[0] = x;
    currentInstance_->previousMouseMotion_[1] = y;
    glutPostRedisplay();
}

void GLViewerPositionalTracking::reshapeCallback(int width, int height) {
    glViewport(0, 0, width, height);
    currentInstance_->camera_.setProjection((float) height / (float) width);
}

void GLViewerPositionalTracking::keyPressedCallback(unsigned char c, int x, int y) {
    currentInstance_->keyStates_[c] = KEY_STATE::DOWN;
    glutPostRedisplay();
}

void GLViewerPositionalTracking::keyReleasedCallback(unsigned char c, int x, int y) {
    currentInstance_->keyStates_[c] = KEY_STATE::UP;
}

void GLViewerPositionalTracking::idle() {
    glutPostRedisplay();
}

Simple3DObjectPositionalTracking::Simple3DObjectPositionalTracking(): isStatic_(false) {
    vaoID_ = 0;
    drawingType_ = GL_TRIANGLES;
    position_ = sl::float3(0, 0, 0);
    rotation_.setIdentity();
}

Simple3DObjectPositionalTracking::Simple3DObjectPositionalTracking(Translation position, bool isStatic): isStatic_(isStatic) {
    vaoID_ = 0;
    drawingType_ = GL_TRIANGLES;
    position_ = position;
    rotation_.setIdentity();
}

Simple3DObjectPositionalTracking::~Simple3DObjectPositionalTracking() {
    if (vaoID_ != 0) {
        glDeleteBuffers(3, vboID_);
        glDeleteVertexArrays(1, &vaoID_);
    }
}

void Simple3DObjectPositionalTracking::addPoint(sl::float3 position, sl::float3 color) {
    addPoint(position.x, position.y, position.z, color.r, color.g, color.b);
}

void Simple3DObjectPositionalTracking::addPoint(float x, float y, float z, float r, float g, float b) {
    vertices_.push_back(x);
    vertices_.push_back(y);
    vertices_.push_back(z);
    colors_.push_back(r);
    colors_.push_back(g);
    colors_.push_back(b);
    indices_.push_back((int) indices_.size());
}

void Simple3DObjectPositionalTracking::addLine(sl::float3 p1, sl::float3 p2, sl::float3 clr) {
    vertices_.push_back(p1.x);
    vertices_.push_back(p1.y);
    vertices_.push_back(p1.z);

    vertices_.push_back(p2.x);
    vertices_.push_back(p2.y);
    vertices_.push_back(p2.z);

    colors_.push_back(clr.r);
    colors_.push_back(clr.g);
    colors_.push_back(clr.b);

    colors_.push_back(clr.r);
    colors_.push_back(clr.g);
    colors_.push_back(clr.b);

    indices_.push_back((int) indices_.size());
    indices_.push_back((int) indices_.size());
}

void Simple3DObjectPositionalTracking::pushToGPU() {
    if (!isStatic_ || vaoID_ == 0) {
        if (vaoID_ == 0) {
            glGenVertexArrays(1, &vaoID_);
            glGenBuffers(3, vboID_);
        }
        glBindVertexArray(vaoID_);
		if (vertices_.size()) {
			glBindBuffer(GL_ARRAY_BUFFER, vboID_[0]);
			glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(float), &vertices_[0], isStatic_ ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
			glVertexAttribPointer(ShaderPositionalTracking::ATTRIB_VERTICES_POS, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(ShaderPositionalTracking::ATTRIB_VERTICES_POS);
		}

		if (colors_.size()) {
			glBindBuffer(GL_ARRAY_BUFFER, vboID_[1]);
			glBufferData(GL_ARRAY_BUFFER, colors_.size() * sizeof(float), &colors_[0], isStatic_ ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
			glVertexAttribPointer(ShaderPositionalTracking::ATTRIB_COLOR_POS, 3, GL_FLOAT, GL_FALSE, 0, 0);
			glEnableVertexAttribArray(ShaderPositionalTracking::ATTRIB_COLOR_POS);
		}

		if (indices_.size()) {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID_[2]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(unsigned int), &indices_[0], isStatic_ ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
		}

        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void Simple3DObjectPositionalTracking::clear() {
    vertices_.clear();
    colors_.clear();
    indices_.clear();
}

void Simple3DObjectPositionalTracking::setDrawingType(GLenum type) {
    drawingType_ = type;
}

void Simple3DObjectPositionalTracking::draw() {
    if(indices_.size() && vaoID_) {
        glBindVertexArray(vaoID_);
        glDrawElements(drawingType_, (GLsizei) indices_.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
}

void Simple3DObjectPositionalTracking::translate(const Translation& t) {
    position_ = position_ + t;
}

void Simple3DObjectPositionalTracking::setPosition(const Translation& p) {
    position_ = p;
}

void Simple3DObjectPositionalTracking::setRT(const Transform& mRT) {
    position_ = mRT.getTranslation();
    rotation_ = mRT.getOrientation();
}

void Simple3DObjectPositionalTracking::rotate(const Orientation& rot) {
    rotation_ = rot * rotation_;
}

void Simple3DObjectPositionalTracking::rotate(const Rotation& m) {
    this->rotate(sl::Orientation(m));
}

void Simple3DObjectPositionalTracking::setRotation(const Orientation& rot) {
    rotation_ = rot;
}

void Simple3DObjectPositionalTracking::setRotation(const Rotation& m) {
    this->setRotation(sl::Orientation(m));
}

const Translation& Simple3DObjectPositionalTracking::getPosition() const {
    return position_;
}

Transform Simple3DObjectPositionalTracking::getModelMatrix() const {
    Transform tmp = Transform::identity();
    tmp.setOrientation(rotation_);
    tmp.setTranslation(position_);
    return tmp;
}

ShaderPositionalTracking::ShaderPositionalTracking(const GLchar* vs, const GLchar* fs) {
    set(vs, fs);
}

void ShaderPositionalTracking::set(const GLchar* vs, const GLchar* fs) {
    if (!compile(verterxId_, GL_VERTEX_SHADER, vs)) {
        std::cout << "ERROR: while compiling vertex shader" << std::endl;
    }
    if (!compile(fragmentId_, GL_FRAGMENT_SHADER, fs)) {
        std::cout << "ERROR: while compiling fragment shader" << std::endl;
    }

    programId_ = glCreateProgram();

    glAttachShader(programId_, verterxId_);
    glAttachShader(programId_, fragmentId_);

    glBindAttribLocation(programId_, ATTRIB_VERTICES_POS, "in_vertex");
    glBindAttribLocation(programId_, ATTRIB_COLOR_POS, "in_texCoord");

    glLinkProgram(programId_);

    GLint errorlk(0);
    glGetProgramiv(programId_, GL_LINK_STATUS, &errorlk);
    if (errorlk != GL_TRUE) {
        std::cout << "ERROR: while linking Shader :" << std::endl;
        GLint errorSize(0);
        glGetProgramiv(programId_, GL_INFO_LOG_LENGTH, &errorSize);

        char *error = new char[errorSize + 1];
        glGetShaderInfoLog(programId_, errorSize, &errorSize, error);
        error[errorSize] = '\0';
        std::cout << error << std::endl;

        delete[] error;
        glDeleteProgram(programId_);
    }
}

ShaderPositionalTracking::~ShaderPositionalTracking() {
    if (verterxId_ != 0 && glIsShader(verterxId_))
        glDeleteShader(verterxId_);
    if (fragmentId_ != 0 && glIsShader(fragmentId_))
        glDeleteShader(fragmentId_);
    if (programId_ != 0 && glIsProgram(programId_))
        glDeleteProgram(programId_);
}

GLuint ShaderPositionalTracking::getProgramId() {
    return programId_;
}

bool ShaderPositionalTracking::compile(GLuint &shaderId, GLenum type, const GLchar* src) {
    shaderId = glCreateShader(type);
    if (shaderId == 0) {
        std::cout << "ERROR: shader type (" << type << ") does not exist" << std::endl;
        return false;
    }
    glShaderSource(shaderId, 1, (const char**) &src, 0);
    glCompileShader(shaderId);

    GLint errorCp(0);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &errorCp);
    if (errorCp != GL_TRUE) {
        std::cout << "ERROR: while compiling Shader :" << std::endl;
        GLint errorSize(0);
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &errorSize);

        char *error = new char[errorSize + 1];
        glGetShaderInfoLog(shaderId, errorSize, &errorSize, error);
        error[errorSize] = '\0';
        std::cout << error << std::endl;

        delete[] error;
        glDeleteShader(shaderId);
        return false;
    }
    return true;
}

const sl::Translation CameraGLPositionalTracking::ORIGINAL_FORWARD = sl::Translation(0, 0, 1);
const sl::Translation CameraGLPositionalTracking::ORIGINAL_UP = sl::Translation(0, 1, 0);
const sl::Translation CameraGLPositionalTracking::ORIGINAL_RIGHT = sl::Translation(1, 0, 0);

CameraGLPositionalTracking::CameraGLPositionalTracking(): znear(0.01f), zfar(10000.f), horizontalFOV(70.f) {
    setProjection(1.78f);
}

CameraGLPositionalTracking::~CameraGLPositionalTracking() {}

void CameraGLPositionalTracking::update() {
    if (sl::Translation::dot(vertical_, up_) < 0)
        vertical_ = vertical_ * -1.f;
    sl::Transform transformation(rotation_, position_);
    vpMatrix_ = projection_ * sl::Transform::inverse(transformation);
}

void CameraGLPositionalTracking::setProjection(float im_ratio) {

    float fov_x = horizontalFOV * M_PI / 180.f;
    float fov_y = horizontalFOV * im_ratio * M_PI / 180.f;

    projection_.setIdentity();
    projection_(0, 0) = 1.f / tanf(fov_x * .5f);
    projection_(1, 1) = 1.f / tanf(fov_y * .5f);
    projection_(2, 2) = -(zfar + znear) / (zfar - znear);
    projection_(3, 2) = -1.f;
    projection_(2, 3) = -(2.f * zfar * znear) / (zfar - znear);
    projection_(3, 3) = 0.f;
}

const sl::Transform& CameraGLPositionalTracking::getViewProjectionMatrix() const {
    return vpMatrix_;
}

void CameraGLPositionalTracking::setDirection(const sl::Translation& direction, const sl::Translation& vertical) {
    sl::Translation dirNormalized = direction;
    dirNormalized.normalize();
    this->rotation_ = sl::Orientation(ORIGINAL_FORWARD, dirNormalized * -1.f);
    updateVectors();
    this->vertical_ = vertical;
    if (sl::Translation::dot(vertical_, up_) < 0.f)
        rotate(sl::Rotation(M_PI, ORIGINAL_FORWARD));
}

void CameraGLPositionalTracking::translate(const sl::Translation& t) {
    position_ = position_ + t;
}

void CameraGLPositionalTracking::setPosition(const sl::Translation& p) {
    position_ = p;
}

void CameraGLPositionalTracking::rotate(const sl::Rotation& m) {
    rotation_ = sl::Orientation(m) * rotation_;
    updateVectors();
}

void CameraGLPositionalTracking::setRotation(const sl::Rotation& m) {
    rotation_ = sl::Orientation(m);
    updateVectors();
}

const sl::Translation& CameraGLPositionalTracking::getForward() const {
    return forward_;
}

const sl::Translation& CameraGLPositionalTracking::getRight() const {
    return right_;
}

const sl::Translation& CameraGLPositionalTracking::getUp() const {
    return up_;
}

const sl::Translation& CameraGLPositionalTracking::getVertical() const {
    return vertical_;
}

void CameraGLPositionalTracking::updateVectors() {
    forward_ = ORIGINAL_FORWARD * rotation_;
    up_ = ORIGINAL_UP * rotation_;
    right_ = sl::Translation(ORIGINAL_RIGHT * -1.f) * rotation_;
}
