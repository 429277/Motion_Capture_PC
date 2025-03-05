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
            ((System.ComponentModel.ISupportInitialize)picLoading).BeginInit();
            ((System.ComponentModel.ISupportInitialize)grdCoordinates).BeginInit();
            SuspendLayout();
            // 
            // btnBodyTracking
            // 
            btnBodyTracking.Location = new Point(44, 70);
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
            picLoading.Location = new Point(156, 63);
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
            grdCoordinates.Location = new Point(44, 226);
            grdCoordinates.Name = "grdCoordinates";
            grdCoordinates.ReadOnly = true;
            grdCoordinates.Size = new Size(334, 169);
            grdCoordinates.TabIndex = 3;
            // 
            // txtCurrentCoordinate
            // 
            txtCurrentCoordinate.Location = new Point(402, 70);
            txtCurrentCoordinate.Name = "txtCurrentCoordinate";
            txtCurrentCoordinate.Size = new Size(255, 23);
            txtCurrentCoordinate.TabIndex = 4;
            // 
            // btnCalibrate
            // 
            btnCalibrate.Location = new Point(44, 28);
            btnCalibrate.Name = "btnCalibrate";
            btnCalibrate.Size = new Size(106, 23);
            btnCalibrate.TabIndex = 5;
            btnCalibrate.Text = "Calibrate";
            btnCalibrate.UseVisualStyleBackColor = true;
            btnCalibrate.Click += btnCalibrate_Click;
            // 
            // txtCameraPosition
            // 
            txtCameraPosition.Location = new Point(402, 26);
            txtCameraPosition.Name = "txtCameraPosition";
            txtCameraPosition.Size = new Size(255, 23);
            txtCameraPosition.TabIndex = 6;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(txtCameraPosition);
            Controls.Add(btnCalibrate);
            Controls.Add(txtCurrentCoordinate);
            Controls.Add(grdCoordinates);
            Controls.Add(picLoading);
            Controls.Add(btnBodyTracking);
            Name = "Form1";
            Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)picLoading).EndInit();
            ((System.ComponentModel.ISupportInitialize)grdCoordinates).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnBodyTracking;
        private PictureBox picLoading;
        private DataGridView grdCoordinates;
        private TextBox txtCurrentCoordinate;
        private Button btnCalibrate;
        private TextBox txtCameraPosition;
    }
}
