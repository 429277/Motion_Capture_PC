using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Motion_Capture_View.Scripts
{
    [StructLayout(LayoutKind.Sequential)]
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

    [StructLayout(LayoutKind.Sequential)]
    public struct RotationSimple
    {
        public float x;
        public float y;
        public float z;

        public RotationSimple(float xRot, float yRot, float zRot)
        {
            x = xRot;
            y = yRot;
            z = zRot;
        }
    }

    public struct PoseSimple
    {
        public Coordinate coordinate;
        public RotationSimple rotation;

        PoseSimple(Coordinate coord, RotationSimple rot)
        {
            coordinate = coord;
            rotation = rot;
        }

    }

    public struct CameraPoseData
    {
        public float transformX;
        public float transformY;
        public float transformZ;

        public float rotationX;
        public float rotationY;
        public float rotationZ;

        public string status;
    }


    [StructLayout(LayoutKind.Sequential)]
    public struct ConfigParameters
    {
        Coordinate initialPosition;
        RotationSimple initialRotation;
        float measurementsPerMinute;

        public ConfigParameters(Coordinate position, RotationSimple rotation, float mpm)
        {
            initialPosition = position;
            initialRotation = rotation;
            measurementsPerMinute = mpm;
        }
    };
}
