namespace Motion_Capture_View
{
    partial class FormCalibration
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            btnSetPosition = new Button();
            txtSetPositionX = new TextBox();
            lblCurrentCameraPosition = new Label();
            txtSetPositionY = new TextBox();
            txtSetPositionZ = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            txtRecievedZ = new TextBox();
            txtRecievedY = new TextBox();
            txtRecievedX = new TextBox();
            SuspendLayout();
            // 
            // btnSetPosition
            // 
            btnSetPosition.Location = new Point(85, 59);
            btnSetPosition.Name = "btnSetPosition";
            btnSetPosition.Size = new Size(124, 23);
            btnSetPosition.TabIndex = 0;
            btnSetPosition.Text = "Set position";
            btnSetPosition.UseVisualStyleBackColor = true;
            btnSetPosition.Click += btnSetPosition_Click;
            // 
            // txtSetPositionX
            // 
            txtSetPositionX.Location = new Point(268, 60);
            txtSetPositionX.Name = "txtSetPositionX";
            txtSetPositionX.Size = new Size(61, 23);
            txtSetPositionX.TabIndex = 1;
            // 
            // lblCurrentCameraPosition
            // 
            lblCurrentCameraPosition.AutoSize = true;
            lblCurrentCameraPosition.Location = new Point(85, 26);
            lblCurrentCameraPosition.Name = "lblCurrentCameraPosition";
            lblCurrentCameraPosition.Size = new Size(138, 15);
            lblCurrentCameraPosition.TabIndex = 2;
            lblCurrentCameraPosition.Text = "Current camera position:";
            // 
            // txtSetPositionY
            // 
            txtSetPositionY.Location = new Point(364, 59);
            txtSetPositionY.Name = "txtSetPositionY";
            txtSetPositionY.Size = new Size(61, 23);
            txtSetPositionY.TabIndex = 4;
            // 
            // txtSetPositionZ
            // 
            txtSetPositionZ.Location = new Point(460, 60);
            txtSetPositionZ.Name = "txtSetPositionZ";
            txtSetPositionZ.Size = new Size(61, 23);
            txtSetPositionZ.TabIndex = 5;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(248, 63);
            label1.Name = "label1";
            label1.Size = new Size(16, 15);
            label1.TabIndex = 6;
            label1.Text = "x:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(342, 62);
            label2.Name = "label2";
            label2.Size = new Size(16, 15);
            label2.TabIndex = 7;
            label2.Text = "y:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(439, 63);
            label3.Name = "label3";
            label3.Size = new Size(15, 15);
            label3.TabIndex = 8;
            label3.Text = "z:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(439, 30);
            label4.Name = "label4";
            label4.Size = new Size(15, 15);
            label4.TabIndex = 14;
            label4.Text = "z:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(342, 29);
            label5.Name = "label5";
            label5.Size = new Size(16, 15);
            label5.TabIndex = 13;
            label5.Text = "y:";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(248, 30);
            label6.Name = "label6";
            label6.Size = new Size(16, 15);
            label6.TabIndex = 12;
            label6.Text = "x:";
            // 
            // txtRecievedZ
            // 
            txtRecievedZ.Location = new Point(460, 27);
            txtRecievedZ.Name = "txtRecievedZ";
            txtRecievedZ.Size = new Size(61, 23);
            txtRecievedZ.TabIndex = 11;
            // 
            // txtRecievedY
            // 
            txtRecievedY.Location = new Point(364, 26);
            txtRecievedY.Name = "txtRecievedY";
            txtRecievedY.Size = new Size(61, 23);
            txtRecievedY.TabIndex = 10;
            // 
            // txtRecievedX
            // 
            txtRecievedX.Location = new Point(268, 27);
            txtRecievedX.Name = "txtRecievedX";
            txtRecievedX.Size = new Size(61, 23);
            txtRecievedX.TabIndex = 9;
            // 
            // FormCalibration
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(640, 146);
            Controls.Add(label4);
            Controls.Add(label5);
            Controls.Add(label6);
            Controls.Add(txtRecievedZ);
            Controls.Add(txtRecievedY);
            Controls.Add(txtRecievedX);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(txtSetPositionZ);
            Controls.Add(txtSetPositionY);
            Controls.Add(lblCurrentCameraPosition);
            Controls.Add(txtSetPositionX);
            Controls.Add(btnSetPosition);
            Name = "FormCalibration";
            Text = "FormCalibration";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnSetPosition;
        private TextBox txtSetPositionX;
        private Label lblCurrentCameraPosition;
        private TextBox txtSetPositionY;
        private TextBox txtSetPositionZ;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private TextBox txtRecievedZ;
        private TextBox txtRecievedY;
        private TextBox txtRecievedX;
    }
}