using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Motion_Capture_View.Scripts
{
    public class Motion_Capture_Controller
    {
        Form1 formReference;

        const string dllLink = @"Motion_Capture_Model.dll";

        #region Externs

        [DllImport(dllLink, CallingConvention = CallingConvention.Cdecl)]
        public static extern int TestDll();

        [DllImport(dllLink, CallingConvention = CallingConvention.Cdecl)]
        public static extern void StartBodyTracking();

        [DllImport(dllLink, CallingConvention = CallingConvention.Cdecl)]
        public static extern void StartPositionalTracking();

        [DllImport(dllLink, CallingConvention = CallingConvention.Cdecl)]
        public static extern void UpdateConfigParameters(ConfigParameters configParameters);

        #endregion

        #region Callbacks

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void CoordinateDataCallback(Coordinate coordinate);

        [DllImport(dllLink, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegisterCoordinateCallback(CoordinateDataCallback callbackCoordinate);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void PositionCallback(CameraPoseData pose);
        [DllImport(dllLink, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RegisterPositionCallback(PositionCallback callbackPosition);

        #endregion

        public Motion_Capture_Controller(Form1 form)
        {
            formReference = form;
            CoordinateDataCallback callbackCoordinate = new CoordinateDataCallback(OnCoordinateReceived);
            RegisterCoordinateCallback(callbackCoordinate);
            PositionCallback callbackPosition = new PositionCallback(OnPositionReceived);
            RegisterPositionCallback(callbackPosition);
        }

        public void OnCoordinateReceived(Coordinate coordinate)
        {
            //formReference.coordinates.Add(coordinate);
            formReference.AddCoordinate(coordinate);
        }
        public void OnPositionReceived(CameraPoseData pose)
        {
            formReference.calibration.UpdateRecievedCameraPostion(pose);
        }

    }
}
