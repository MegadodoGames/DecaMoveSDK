using System;

namespace DecaSDK.Unity
{
    public class SharedDisposable<T> : IDisposable where T : class, IDisposable
    {
        private class Target
        {
            public T value;
            public uint count;
        }

        public enum Type
        {
            Strong,
            Weak
        }

        public SharedDisposable(Func<T> create)
        {
            _type = Type.Strong;
            _target = new Target()
            {
                value = create(),
                count = 1,
            };
        }

        public SharedDisposable(SharedDisposable<T> share, Type type = Type.Strong)
        {
            _target = share._target;
            _type = type;
            if (_type == Type.Strong)
            {
                _target.count++;
            }
        }

        public SharedDisposable<T> Lock()
        {
            if (_type == Type.Weak && _target.count == 0)
            {
                return null;
            }

            return new SharedDisposable<T>(this);
        }

        public void Dispose()
        {
            if (_type == Type.Strong)
            {
                if (--_target.count == 0)
                {
                    Value.Dispose();
                }
            }
        }

        private Target _target = null;
        public T Value { get => _target.value; }
        private Type _type;
    }

    public class SharedMove : IDisposable
    {
        public static SharedDisposable<SharedMove> Instance
        {
            get
            {
                SharedDisposable<SharedMove> ret;
                if (_weakInstance == null ||
                    (ret = _weakInstance.Lock()) == null)
                {
                    ret = new SharedDisposable<SharedMove>(() => new SharedMove());
                    _weakInstance = ret;
                }
                return ret;
            }
        }
        private static SharedDisposable<SharedMove> _weakInstance = null;
        private SharedMove()
        {
            _move = new DecaSDK.Move(
                /* OnFeedback */ (feedback) =>
                {
                    lock (this) { if (OnFeedback != null) OnFeedback(feedback); }
                },
                /* OnBatteryUpdate */ (charge) =>
                {
                    lock (this) { if (OnBatteryUpdate != null) OnBatteryUpdate(charge); }

                },
                /* OnOrientationUpdate */ (quaternion, accuracy, yawDrift) =>
                {
                    lock (this) { if (OnOrientationUpdate != null) OnOrientationUpdate(quaternion, accuracy, yawDrift); }
                },
                /* OnPositionUpdate */ (x, y, z) =>
                {
                    lock (this) { if (OnPositionUpdate != null) OnPositionUpdate(x, y, z); }
                },
                /* OnStateUpdate */ (state) =>
                {
                    lock (this)
                    {
                        _moveState = state;
                        if (OnStateUpdate != null) OnStateUpdate(state);
                    }
                },
                /* OnImuCalibrationRequest */ () =>
                {
                    lock (this) { if (OnImuCalibrationRequest != null) OnImuCalibrationRequest(); }
                },
                /* OnLogMessage */ (logLevel, message) =>
                {
                    lock (this)
                    {
                        if (OnLogMessage != null)
                        {
                            OnLogMessage(logLevel, message);
                            return;
                        }
                    }
                    Console.WriteLine(message);
                });
        }
        public void Dispose()
        {
            if (_move != null)
            {
                _move.Dispose();
            }
        }

        public void AddCallbacks(Move.OnFeedbackDelegate OnFeedback,
                                 Move.OnBatteryUpdateDelegate OnBatteryUpdate,
                                 Move.OnOrientationUpdateDelegate OnOrientationUpdate,
                                 Move.OnPositionUpdateDelegate OnPositionUpdate,
                                 Move.OnStateUpdateDelegate OnStateUpdate,
                                 Move.OnImuCalibrationRequestDelegate OnImuCalibrationRequest,
                                 Move.OnLogMessage OnLogMessage)
        {
            lock (this)
            {
                if (OnFeedback != null) this.OnFeedback += OnFeedback;
                if (OnBatteryUpdate != null) this.OnBatteryUpdate += OnBatteryUpdate;
                if (OnOrientationUpdate != null) this.OnOrientationUpdate += OnOrientationUpdate;
                if (OnPositionUpdate != null) this.OnPositionUpdate += OnPositionUpdate;
                if (OnStateUpdate != null) this.OnStateUpdate += OnStateUpdate;
                if (OnImuCalibrationRequest != null) this.OnImuCalibrationRequest += OnImuCalibrationRequest;
                if (OnLogMessage != null) this.OnLogMessage += OnLogMessage;

                if (OnStateUpdate != null)
                {
                    OnStateUpdate(_moveState);
                }
            }
        }
        public void SendHaptic()
        {
            _move.SendHaptic();
        }
        public void StopHaptic()
        {
            _move.StopHaptic();
        }
        public void SendBlink(int durationSeconds, int frequency)
        {
            _move.SendBlink(durationSeconds, frequency);
        }
        public void Calibrate(float forwardX, float forwardY)
        {
            _move.Calibrate(forwardX, forwardY);
        }
        public void StartImuCalibration()
        {
            _move.StartImuCalibration();
        }
        public void StopImuCalibration()
        {
            _move.StopImuCalibration();
        }
        public void AbortImuCalibration()
        {
            _move.AbortImuCalibration();
        }

        private Move.OnFeedbackDelegate OnFeedback;
        private Move.OnBatteryUpdateDelegate OnBatteryUpdate;
        private Move.OnOrientationUpdateDelegate OnOrientationUpdate;
        private Move.OnPositionUpdateDelegate OnPositionUpdate;
        private Move.OnStateUpdateDelegate OnStateUpdate;
        private Move.OnImuCalibrationRequestDelegate OnImuCalibrationRequest;
        private Move.OnLogMessage OnLogMessage;

        private Move.State _moveState = Move.State.Closed;

        private Move _move;
    }

    public static class QuaternionExtension
    {
        public static UnityEngine.Quaternion ToUnity(this Move.Quaternion quat)
        {
            return new UnityEngine.Quaternion(
                quat.x,
                quat.w,
                quat.y,
                quat.z
            ) * UnityEngine.Quaternion.Euler(-90, 0, 0);
        }
    }
}
