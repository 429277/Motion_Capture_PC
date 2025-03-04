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
    }
}
