namespace Motion_Capture_View
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            btnBodyTracking = new Button();
            picLoading = new PictureBox();
            grdCoordinates = new DataGridView();
            txtCurrentCoordinate = new TextBox();
            btnCalibrate = new Button();
            txtCameraPosition = new TextBox();
            tabControl1 = new TabControl();
            tabMain = new TabPage();
            tabSettings = new TabPage();
            label10 = new Label();
            boxBodyType = new ComboBox();
            txtSettingMeasurementPerMinute = new TextBox();
            label9 = new Label();
            label5 = new Label();
            txtSettingRZ = new TextBox();
            txtSettingRY = new TextBox();
            txtSettingRX = new TextBox();
            label6 = new Label();
            label7 = new Label();
            label8 = new Label();
            label4 = new Label();
            txtSettingZ = new TextBox();
            txtSettingY = new TextBox();
            txtSettingX = new TextBox();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            button3 = new Button();
            button2 = new Button();
            btnSaveSettings = new Button();
            tabPage1 = new TabPage();
            button4 = new Button();
            ((System.ComponentModel.ISupportInitialize)picLoading).BeginInit();
            ((System.ComponentModel.ISupportInitialize)grdCoordinates).BeginInit();
            tabControl1.SuspendLayout();
            tabMain.SuspendLayout();
            tabSettings.SuspendLayout();
            tabPage1.SuspendLayout();
            SuspendLayout();
            // 
            // btnBodyTracking
            // 
            btnBodyTracking.Location = new Point(6, 35);
            btnBodyTracking.Name = "btnBodyTracking";
            btnBodyTracking.Size = new Size(106, 23);
            btnBodyTracking.TabIndex = 0;
            btnBodyTracking.Text = "Body Tracking";
            btnBodyTracking.UseVisualStyleBackColor = true;
            btnBodyTracking.Click += btnBodyTracking_Click;
            // 
            // picLoading
            // 
            picLoading.Image = Properties.Resources.Throbber;
            picLoading.InitialImage = null;
            picLoading.Location = new Point(6, 362);
            picLoading.Name = "picLoading";
            picLoading.Size = new Size(30, 30);
            picLoading.SizeMode = PictureBoxSizeMode.StretchImage;
            picLoading.TabIndex = 2;
            picLoading.TabStop = false;
            picLoading.Visible = false;
            // 
            // grdCoordinates
            // 
            grdCoordinates.AllowUserToAddRows = false;
            grdCoordinates.AllowUserToDeleteRows = false;
            grdCoordinates.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            grdCoordinates.Location = new Point(581, 223);
            grdCoordinates.Name = "grdCoordinates";
            grdCoordinates.ReadOnly = true;
            grdCoordinates.Size = new Size(181, 169);
            grdCoordinates.TabIndex = 3;
            // 
            // txtCurrentCoordinate
            // 
            txtCurrentCoordinate.Location = new Point(225, 36);
            txtCurrentCoordinate.Name = "txtCurrentCoordinate";
            txtCurrentCoordinate.Size = new Size(255, 23);
            txtCurrentCoordinate.TabIndex = 4;
            // 
            // btnCalibrate
            // 
            btnCalibrate.Location = new Point(6, 6);
            btnCalibrate.Name = "btnCalibrate";
            btnCalibrate.Size = new Size(106, 23);
            btnCalibrate.TabIndex = 5;
            btnCalibrate.Text = "Position tracking";
            btnCalibrate.UseVisualStyleBackColor = true;
            btnCalibrate.Click += btnCalibrate_Click;
            // 
            // txtCameraPosition
            // 
            txtCameraPosition.Location = new Point(225, 7);
            txtCameraPosition.Name = "txtCameraPosition";
            txtCameraPosition.Size = new Size(255, 23);
            txtCameraPosition.TabIndex = 6;
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabMain);
            tabControl1.Controls.Add(tabSettings);
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Location = new Point(12, 12);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(776, 426);
            tabControl1.TabIndex = 7;
            // 
            // tabMain
            // 
            tabMain.Controls.Add(btnCalibrate);
            tabMain.Controls.Add(grdCoordinates);
            tabMain.Controls.Add(txtCurrentCoordinate);
            tabMain.Controls.Add(picLoading);
            tabMain.Controls.Add(txtCameraPosition);
            tabMain.Controls.Add(btnBodyTracking);
            tabMain.Location = new Point(4, 24);
            tabMain.Name = "tabMain";
            tabMain.Padding = new Padding(3);
            tabMain.Size = new Size(768, 398);
            tabMain.TabIndex = 0;
            tabMain.Text = "Main";
            tabMain.UseVisualStyleBackColor = true;
            // 
            // tabSettings
            // 
            tabSettings.Controls.Add(label10);
            tabSettings.Controls.Add(boxBodyType);
            tabSettings.Controls.Add(txtSettingMeasurementPerMinute);
            tabSettings.Controls.Add(label9);
            tabSettings.Controls.Add(label5);
            tabSettings.Controls.Add(txtSettingRZ);
            tabSettings.Controls.Add(txtSettingRY);
            tabSettings.Controls.Add(txtSettingRX);
            tabSettings.Controls.Add(label6);
            tabSettings.Controls.Add(label7);
            tabSettings.Controls.Add(label8);
            tabSettings.Controls.Add(label4);
            tabSettings.Controls.Add(txtSettingZ);
            tabSettings.Controls.Add(txtSettingY);
            tabSettings.Controls.Add(txtSettingX);
            tabSettings.Controls.Add(label3);
            tabSettings.Controls.Add(label2);
            tabSettings.Controls.Add(label1);
            tabSettings.Controls.Add(button3);
            tabSettings.Controls.Add(button2);
            tabSettings.Controls.Add(btnSaveSettings);
            tabSettings.Location = new Point(4, 24);
            tabSettings.Name = "tabSettings";
            tabSettings.Padding = new Padding(3);
            tabSettings.Size = new Size(768, 398);
            tabSettings.TabIndex = 1;
            tabSettings.Text = "Settings";
            tabSettings.UseVisualStyleBackColor = true;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(16, 181);
            label10.Name = "label10";
            label10.Size = new Size(60, 15);
            label10.TabIndex = 20;
            label10.Text = "Bodytype:";
            // 
            // boxBodyType
            // 
            boxBodyType.FormattingEnabled = true;
            boxBodyType.Items.AddRange(new object[] { "18", "34", "38" });
            boxBodyType.Location = new Point(171, 178);
            boxBodyType.Name = "boxBodyType";
            boxBodyType.Size = new Size(121, 23);
            boxBodyType.TabIndex = 19;
            // 
            // txtSettingMeasurementPerMinute
            // 
            txtSettingMeasurementPerMinute.Location = new Point(171, 139);
            txtSettingMeasurementPerMinute.Name = "txtSettingMeasurementPerMinute";
            txtSettingMeasurementPerMinute.Size = new Size(100, 23);
            txtSettingMeasurementPerMinute.TabIndex = 18;
            txtSettingMeasurementPerMinute.Text = "60";
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(16, 142);
            label9.Name = "label9";
            label9.Size = new Size(149, 15);
            label9.TabIndex = 17;
            label9.Text = "Measurements per minute:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(10, 68);
            label5.Name = "label5";
            label5.Size = new Size(85, 15);
            label5.TabIndex = 16;
            label5.Text = "Initial position:";
            // 
            // txtSettingRZ
            // 
            txtSettingRZ.Location = new Point(409, 68);
            txtSettingRZ.Name = "txtSettingRZ";
            txtSettingRZ.Size = new Size(100, 23);
            txtSettingRZ.TabIndex = 15;
            txtSettingRZ.Text = "0";
            // 
            // txtSettingRY
            // 
            txtSettingRY.Location = new Point(261, 65);
            txtSettingRY.Name = "txtSettingRY";
            txtSettingRY.Size = new Size(100, 23);
            txtSettingRY.TabIndex = 14;
            txtSettingRY.Text = "0";
            // 
            // txtSettingRX
            // 
            txtSettingRX.Location = new Point(118, 65);
            txtSettingRX.Name = "txtSettingRX";
            txtSettingRX.Size = new Size(100, 23);
            txtSettingRX.TabIndex = 13;
            txtSettingRX.Text = "0";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(390, 71);
            label6.Name = "label6";
            label6.Size = new Size(15, 15);
            label6.TabIndex = 12;
            label6.Text = "z:";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(242, 68);
            label7.Name = "label7";
            label7.Size = new Size(16, 15);
            label7.TabIndex = 11;
            label7.Text = "y:";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(99, 68);
            label8.Name = "label8";
            label8.Size = new Size(16, 15);
            label8.TabIndex = 10;
            label8.Text = "x:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(10, 34);
            label4.Name = "label4";
            label4.Size = new Size(85, 15);
            label4.TabIndex = 9;
            label4.Text = "Initial position:";
            // 
            // txtSettingZ
            // 
            txtSettingZ.Location = new Point(409, 31);
            txtSettingZ.Name = "txtSettingZ";
            txtSettingZ.Size = new Size(100, 23);
            txtSettingZ.TabIndex = 8;
            txtSettingZ.Text = "0";
            // 
            // txtSettingY
            // 
            txtSettingY.Location = new Point(261, 31);
            txtSettingY.Name = "txtSettingY";
            txtSettingY.Size = new Size(100, 23);
            txtSettingY.TabIndex = 7;
            txtSettingY.Text = "0";
            // 
            // txtSettingX
            // 
            txtSettingX.Location = new Point(118, 31);
            txtSettingX.Name = "txtSettingX";
            txtSettingX.Size = new Size(100, 23);
            txtSettingX.TabIndex = 6;
            txtSettingX.Text = "0";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(390, 34);
            label3.Name = "label3";
            label3.Size = new Size(15, 15);
            label3.TabIndex = 5;
            label3.Text = "z:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(242, 34);
            label2.Name = "label2";
            label2.Size = new Size(16, 15);
            label2.TabIndex = 4;
            label2.Text = "y:";
            label2.Click += label2_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(99, 34);
            label1.Name = "label1";
            label1.Size = new Size(16, 15);
            label1.TabIndex = 3;
            label1.Text = "x:";
            // 
            // button3
            // 
            button3.Location = new Point(171, 369);
            button3.Name = "button3";
            button3.Size = new Size(75, 23);
            button3.TabIndex = 2;
            button3.Text = "Default";
            button3.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            button2.Location = new Point(90, 369);
            button2.Name = "button2";
            button2.Size = new Size(75, 23);
            button2.TabIndex = 1;
            button2.Text = "Revert";
            button2.UseVisualStyleBackColor = true;
            // 
            // btnSaveSettings
            // 
            btnSaveSettings.Location = new Point(6, 369);
            btnSaveSettings.Name = "btnSaveSettings";
            btnSaveSettings.Size = new Size(75, 23);
            btnSaveSettings.TabIndex = 0;
            btnSaveSettings.Text = "Save";
            btnSaveSettings.UseVisualStyleBackColor = true;
            btnSaveSettings.Click += btnSaveSettings_Click;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(button4);
            tabPage1.Location = new Point(4, 24);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(768, 398);
            tabPage1.TabIndex = 2;
            tabPage1.Text = "Data extraction";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            button4.Location = new Point(16, 16);
            button4.Name = "button4";
            button4.Size = new Size(98, 23);
            button4.TabIndex = 0;
            button4.Text = "Get Json file";
            button4.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(tabControl1);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)picLoading).EndInit();
            ((System.ComponentModel.ISupportInitialize)grdCoordinates).EndInit();
            tabControl1.ResumeLayout(false);
            tabMain.ResumeLayout(false);
            tabMain.PerformLayout();
            tabSettings.ResumeLayout(false);
            tabSettings.PerformLayout();
            tabPage1.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private Button btnBodyTracking;
        private PictureBox picLoading;
        private DataGridView grdCoordinates;
        private TextBox txtCurrentCoordinate;
        private Button btnCalibrate;
        private TextBox txtCameraPosition;
        private TabControl tabControl1;
        private TabPage tabMain;
        private TabPage tabSettings;
        private Button btnSaveSettings;
        private TextBox txtSettingZ;
        private TextBox txtSettingY;
        private TextBox txtSettingX;
        private Label label3;
        private Label label2;
        private Label label1;
        private Button button3;
        private Button button2;
        private Label label5;
        private TextBox txtSettingRZ;
        private TextBox txtSettingRY;
        private TextBox txtSettingRX;
        private Label label6;
        private Label label7;
        private Label label8;
        private Label label4;
        private Label label9;
        private TextBox txtSettingMeasurementPerMinute;
        private Label label10;
        private ComboBox boxBodyType;
        private TabPage tabPage1;
        private Button button4;
    }
}
