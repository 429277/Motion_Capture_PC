using Motion_Capture_View.Scripts;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace Motion_Capture_View
{
    public partial class Form1 : Form
    {
        Motion_Capture_Controller Controller;
        public FormCalibration calibration;
        public BindingList<Coordinate> coordinates = new BindingList<Coordinate>();
        public DataTable dataTable = new();

        public Form1()
        {
            InitializeComponent();
            Controller = new Motion_Capture_Controller(this);
            grdCoordinates.DataSource = coordinates;
        }

        public void AddCoordinate(Coordinate coordinates)
        {
            txtCurrentCoordinate.Text = $"x: {coordinates.x} y: {coordinates.y} z: {coordinates.z}";
        }

        public void ToggleLoadingSymbol(bool loading)
        {
            picLoading.Visible = loading;
        }

        private void btnBodyTracking_Click(object sender, EventArgs e)
        {
            Cursor.Current = Cursors.WaitCursor;
            ToggleLoadingSymbol(true);
            Motion_Capture_Controller.StartBodyTracking();
        }

        private void btnCalibrate_Click(object sender, EventArgs e)
        {
            Cursor.Current = Cursors.WaitCursor;
            calibration = new FormCalibration();
            calibration.Show();
            Motion_Capture_Controller.StartPositionalTracking();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void btnSaveSettings_Click(object sender, EventArgs e)
        {
            float x;
            float y;
            float z;
            float rx;
            float ry;
            float rz;
            float measurementsPerMinute;

            float.TryParse(txtSettingX.Text, out x);
            float.TryParse(txtSettingY.Text, out y);
            float.TryParse(txtSettingZ.Text, out z);
            float.TryParse(txtSettingRX.Text, out rx);
            float.TryParse(txtSettingRY.Text, out ry);
            float.TryParse(txtSettingRZ.Text, out rz);
            float.TryParse(txtSettingMeasurementPerMinute.Text, out measurementsPerMinute);

            Coordinate initialPosition = new Coordinate(x,y,z);
            RotationSimple initialRotation = new RotationSimple(rx,ry,rz);
            ConfigParameters config = new ConfigParameters(initialPosition, initialRotation, measurementsPerMinute);
            Motion_Capture_Controller.UpdateConfigParameters(config);
        }
    }
}
