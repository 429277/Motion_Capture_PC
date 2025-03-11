using Motion_Capture_View.Scripts;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Motion_Capture_View
{
    public partial class FormCalibration : Form
    {
        public FormCalibration()
        {
            InitializeComponent();
        }

        public void UpdateRecievedCameraPostion(PoseSimple pose)
        {
            lblReceivedStatus.Text = pose.status;
            if (pose.status.Equals("OK"))
            {
                txtRecievedX.Text = pose.transformX.ToString();
                txtRecievedY.Text = pose.transformY.ToString();
                txtRecievedZ.Text = pose.transformZ.ToString();
                txtRecievedRotationX.Text = pose.rotationX.ToString();
                txtRecievedRotationY.Text = pose.rotationY.ToString();
                txtRecievedRotationZ.Text = pose.rotationZ.ToString();
            }
        }

        private void btnSetPosition_Click(object sender, EventArgs e)
        {
            float x;
            float y;
            float z;
            float.TryParse(txtSetPositionX.Text, out x);
            float.TryParse(txtSetPositionY.Text, out y);
            float.TryParse(txtSetPositionZ.Text, out z);

            Motion_Capture_Controller.SetCameraPosition(new Coordinate(x, y, z));
        }
    }
}
