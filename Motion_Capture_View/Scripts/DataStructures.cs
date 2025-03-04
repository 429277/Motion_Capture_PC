using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Motion_Capture_View.Scripts
{
    public struct Coordinate
    {
        public float x {  get; set; }
        public float y { get; set; }
        public float z { get; set; }

        public Coordinate(float xCoord, float yCoord, float zCoord)
        {
            x = xCoord;
            y = yCoord;
            z = zCoord;
        }
    }
}
