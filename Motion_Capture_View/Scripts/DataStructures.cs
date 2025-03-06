using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Motion_Capture_View.Scripts
{
    public struct Coordinate
    {
        public float x;
        public float y;
        public float z;

        public Coordinate(float xCoord, float yCoord, float zCoord)
        {
            x = xCoord;
            y = yCoord;
            z = zCoord;
        }
    }

    public struct RotationPass
    {
        public float x;
        public float y;
        public float z;

        public RotationPass(float xRot, float yRot, float zRot)
        {
            x = xRot;
            y = yRot;
            z = zRot;
        }
    }

    public struct PoseSimple
    {
        public float transformX;
        public float transformY;
        public float transformZ;

        public float rotationX;
        public float rotationY;
        public float rotationZ;
    }


    public struct PosePass
    {
        public Coordinate coordinate;
        public RotationPass rotation;

        PosePass(Coordinate coord, RotationPass rot)
        {
            coordinate = coord;
            rotation = rot;
        }

    }
}
