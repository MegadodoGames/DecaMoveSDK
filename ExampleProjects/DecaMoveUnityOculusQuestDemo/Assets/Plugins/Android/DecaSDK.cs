using System;
using System.Runtime.InteropServices;

namespace DecaSDK
{
    public class Move : IDisposable
    {
        public enum State
        {
            Closed = 0,
            Open,
            Paired,
            Streaming
        }
        [StructLayout(LayoutKind.Sequential, Pack = 8)]
        public struct Quaternion
        {
            public float x;
            public float y;
            public float z;
            public float w;
        };
        public enum Feedback
        {
            EnteringSleep,
            LeavingSleep,
            ShuttingDown,
            SingleClick,
            DoubleClick,
            TripleClick,
        };
        public enum Accuracy
        {
            Unreliable,
            Low,
            Medium,
            High,
            Unspecified
        };
        public enum Status
        {
            Success = 0,
            ErrorUSB,
            ErrorNotConnected,
        };
        public enum LogLevel
        {
            Trace = 0,
            Debug,
            Info,
            Warn,
            Err,
            Critical,
        };
        public class NativeCallFailedException : Exception
        {
            public Status Status;
            public NativeCallFailedException(Status status) : base()
            {
                Status = status;
            }
            public override string Message
            {
                get => Status.ToString();
            }
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void on_feedback_callback(Feedback feedback, IntPtr handle);
        private static void OnFeedbackWrap(Feedback feedback, IntPtr handle)
        {
            (GCHandle.FromIntPtr(handle).Target as Move)._onFeedback(feedback);
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void battery_update_callback(float charge, IntPtr handle);
        private static void OnBatteryUpdateWrap(float charge, IntPtr handle)
        {
            (GCHandle.FromIntPtr(handle).Target as Move)._onBatteryUpdate(charge);
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void orientation_update_callback(Quaternion quaternion, Accuracy accuracy, float yawDrift, IntPtr handle);
        private static void OnOrientationUpdateWrap(Quaternion quaternion, Accuracy accuracy, float yawDrift, IntPtr handle)
        {
            (GCHandle.FromIntPtr(handle).Target as Move)._onOrientationUpdate(quaternion, accuracy, yawDrift);
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void position_update_callback(float x, float y, float z, IntPtr handle);
        private static void OnPositionUpdateWrap(float x, float y, float z, IntPtr handle)
        {
            (GCHandle.FromIntPtr(handle).Target as Move)._onPositionUpdate(x, y, z);
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void on_state_callback(State state, IntPtr handle);
        private static void OnStateUpdateWrap(State state, IntPtr handle)
        {
            (GCHandle.FromIntPtr(handle).Target as Move)._onStateUpdate(state);
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        private delegate void log_callback(LogLevel logLevel, string logMessage, IntPtr handle);
        private static void LogCallbackWrap(LogLevel logLevel, string logMessage, IntPtr handle)
        {
            (GCHandle.FromIntPtr(handle).Target as Move)._onLogMessage(logLevel, logMessage);
        }

        [StructLayout(LayoutKind.Sequential, Pack = 8)]
        private struct deca_move_callbacks
        {
            public IntPtr user_data;
            public on_feedback_callback feedback_cb;
            public battery_update_callback battery_update_cb;
            public orientation_update_callback orientation_update_cb;
            public position_update_callback position_update_cb;
            public on_state_callback state_update_cb;
        };

        private const UInt32 kDecaMoveEnvComLib = 1 << 0;

        [StructLayout(LayoutKind.Sequential, Pack = 8)]
        private struct deca_move_env_desc
        {
            public UInt32 flags;
            public log_callback log_cb;
            public IntPtr log_user_data;
        };

        [DllImport("deca_sdk")]
        private static extern int decaMoveInit(
            deca_move_env_desc envDesc,
            deca_move_callbacks callbacks,
            out IntPtr decaMove);
        [DllImport("deca_sdk")]
        private static extern int decaMoveSendHaptic(IntPtr decaMove);
        [DllImport("deca_sdk")]
        private static extern int decaMoveCalibrate(IntPtr decaMove, float forwardX, float forwardY);
        [DllImport("deca_sdk")]
        private static extern void decaMoveRelease(IntPtr decaMove);

        public delegate void OnFeedbackDelegate(Feedback feedback);
        public delegate void OnBatteryUpdateDelegate(float charge);
        public delegate void OnOrientationUpdateDelegate(Quaternion quaternion, Accuracy accuracy, float yawDrift);
        public delegate void OnPositionUpdateDelegate(float x, float y, float z);
        public delegate void OnStateUpdateDelegate(State state);
        public delegate void OnLogMessage(LogLevel logLevel, string msg);

        private OnFeedbackDelegate _onFeedback;
        private OnBatteryUpdateDelegate _onBatteryUpdate;
        private OnOrientationUpdateDelegate _onOrientationUpdate;
        private OnPositionUpdateDelegate _onPositionUpdate;
        private OnStateUpdateDelegate _onStateUpdate;
        private OnLogMessage _onLogMessage;

        public Move(OnFeedbackDelegate onFeedback,
                    OnBatteryUpdateDelegate onBatteryUpdate,
                    OnOrientationUpdateDelegate onOrientationUpdate,
                    OnPositionUpdateDelegate onPositionUpdate,
                    OnStateUpdateDelegate onStateUpdate,
                    OnLogMessage onLogMessage)
        {
            _onFeedback = onFeedback;
            _onBatteryUpdate = onBatteryUpdate;
            _onOrientationUpdate = onOrientationUpdate;
            _onPositionUpdate = onPositionUpdate;
            _onStateUpdate = onStateUpdate;
            _onLogMessage = onLogMessage;

            _callbackHandle = GCHandle.Alloc(this);
            _callbacks = new deca_move_callbacks();
            _callbacks.user_data = GCHandle.ToIntPtr(_callbackHandle);
            if (_onFeedback != null) { _callbacks.feedback_cb = OnFeedbackWrap; }
            if (_onBatteryUpdate != null) { _callbacks.battery_update_cb = OnBatteryUpdateWrap; }
            if (_onOrientationUpdate != null) { _callbacks.orientation_update_cb = OnOrientationUpdateWrap; }
            if (_onPositionUpdate != null) { _callbacks.position_update_cb = OnPositionUpdateWrap; }
            if (_onStateUpdate != null) { _callbacks.state_update_cb = OnStateUpdateWrap; }

            _envDesc = new deca_move_env_desc();
            _envDesc.flags = kDecaMoveEnvComLib;
            if (_onLogMessage != null)
            {
                _envDesc.log_cb = LogCallbackWrap;
                _envDesc.log_user_data = GCHandle.ToIntPtr(_callbackHandle);
            }

            HandleNativeCall(decaMoveInit(_envDesc, _callbacks, out _decaMove));
        }
        public void Dispose()
        {
            if (_decaMove != IntPtr.Zero)
            {
                decaMoveRelease(_decaMove);
                _callbackHandle.Free();
                _decaMove = IntPtr.Zero;
            }
        }
        public void SendHaptic()
        {
            HandleNativeCall(decaMoveSendHaptic(_decaMove));
        }
        public void Calibrate(float forwardX, float forwardY)
        {
            HandleNativeCall(decaMoveCalibrate(_decaMove, forwardX, forwardY));
        }

        private void HandleNativeCall(int nativeStatus)
        {
            var status = (Status)nativeStatus;
            if (status != Status.Success)
            {
                throw new NativeCallFailedException(status);
            }
        }

        private IntPtr _decaMove;
        private GCHandle _callbackHandle;
        private deca_move_callbacks _callbacks;
        private deca_move_env_desc _envDesc;
    }
}
