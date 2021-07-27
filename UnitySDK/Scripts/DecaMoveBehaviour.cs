/*  
 * If you need any help please message us in our discord where us or our community would be hapy to help you out.
 * 
 * If you find a bug please also leave a bug report in the #bug-reports channel of our discord 
 * 
 * (Everything is on the discord)
 * 
 * Discord: https://discord.gg/9AQnUhZRt7
 */
using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;
using DecaSDK.Unity;

namespace DecaSDK
{
    public class DecaMoveBehaviour : MonoBehaviour
    {
        // Used for calibration
        [Tooltip("Assign this to whatever you want the deca move to match rotations with when you callibrate this, usually your hmd position.")]
        public Transform head;


        public bool updatePositon;
        [Tooltip("This option makes it so that the DecaMove only rotates around the y axis, often this is more usefull")]
        public bool onlyRotateY;
        public Vector3 position => _position;
        private Vector3 _position;

        // This is the raw, uncalibrated rotation of the move
        public Quaternion rotation => _rotation;
        private Quaternion _rotation;

        // This is the uncalibrated rotation of the move, but only around a single axis, if you want the callbrated version rotate it by the yOffset variable
        public Quaternion yRotation => Quaternion.AngleAxis(_rotation.eulerAngles.y, Vector3.up);

        // The offset between raw rotation and the calibrated rotation, in radians
        public float yOffset => _yOffset;
        private float _yOffset;
        public float battery => _battery;
        private float _battery;
        public Move.Accuracy accuracy => _accuracy;
        private Move.Accuracy _accuracy;

        // Please note that the button will apear to have some very slight latency, this is because the single/double/triple click calculations are done on the firmware side and it waits to make sure the button isn't going to be pressed agian
        public UnityEvent onButtonClicked;
        public UnityEvent onButtonDoubleClicked;
        public UnityEvent onButtonTrippleClicked;

        // The current state of the connection with the Move: Closed, Open, streaming, etc.
        public Move.State state => _state;
        private Move.State _state;

        // Get if the move is currently asleep
        public bool sleeping => _sleeping;
        private bool _sleeping = true;

        private SharedDisposable<SharedMove> _decaMove;
        // Event callbacks are on another thread so we need to store them until we can process them from the main thread
        private Queue<Move.Feedback> eventQueue = new Queue<Move.Feedback>();

        private void Start()
        {
            try
            {
                Move.OnStateUpdateDelegate OnStateUpdate = (Move.State state) =>
                {
                    lock (this)
                    {
                        _state = state;
                    }
                    Debug.Log("State: " + state);
                };
                Move.OnFeedbackDelegate OnFeedback = (feedback) =>
                {
                    // These are called from another thread so we need to use lock to prevent race conditions
                    lock (this)
                    {
                        eventQueue.Enqueue(feedback);
                    }
                    Debug.Log("Feedback: " + feedback);
                };
                Move.OnLogMessage OnLogMessage = (Move.LogLevel logLevel, string msg) =>
                {
                    
                    // Debug messages get logged here.
                    Debug.Log("DecaLog: \"" + msg + "\" logLevel: " + logLevel);
                };
                Move.OnBatteryUpdateDelegate OnBatteryUpdate = (charge) =>
                {
                    lock (this)
                    {
                        _battery = charge;
                    }
                    Debug.Log("Battery charge: " + charge);
                };
                Move.OnOrientationUpdateDelegate OnOrientationUpdate = (quaternion, accuracy, yawCalibration) =>
                {
                    // Update our local variables, again we can't change transform from a different thread so we update them later.
                    lock (this)
                    {
                        _rotation = quaternion.ToUnity();
                        _yOffset = yawCalibration;
                        _accuracy = accuracy;
                    }
                };
                Move.OnImuCalibrationRequestDelegate OnImuCalibrationRequest = () =>
                {
                    Console.WriteLine("Deca Move requested IMU calibration");
                };
                Move.OnPositionUpdateDelegate OnPositionUpdate = (x, y, z) =>
                {
                    // Position from a 3 dof acessory? Yep.
                    lock (this)
                    {
                        _position = new Vector3(x, y, z);
                    }
                };


                _decaMove = SharedMove.Instance;
                _decaMove.Value.AddCallbacks(OnFeedback, OnBatteryUpdate, OnOrientationUpdate, OnPositionUpdate, OnStateUpdate, OnImuCalibrationRequest, OnLogMessage);
            }
            catch (Exception e)
            {
                Debug.LogError("Exception occured in DecaMoveBehaviour: " + e);
            }
        }

        private void Update()
        {
            if (!onlyRotateY)
                transform.localRotation = Quaternion.AngleAxis(Mathf.Rad2Deg * _yOffset, Vector3.up) * _rotation;
            else 
                transform.localRotation = Quaternion.AngleAxis(Mathf.Rad2Deg * _yOffset, Vector3.up) * yRotation;

            if (updatePositon)
                transform.position = Quaternion.AngleAxis(Mathf.Rad2Deg * _yOffset, Vector3.up) * _position;

            // Execute the events from the event queue
            while (0 < eventQueue.Count)
            {
                Move.Feedback e = eventQueue.Dequeue();
                switch (e)
                {
                    case Move.Feedback.EnteringSleep:
                        // If you want to add your own events here be our guest.
                        _sleeping = true;
                        break;
                    case Move.Feedback.LeavingSleep:
                        _sleeping = false;
                        break;
                    case Move.Feedback.ShuttingDown:
                        _sleeping = true;
                        break;
                    case Move.Feedback.SingleClick:
                        onButtonClicked.Invoke();
                        break;
                    case Move.Feedback.DoubleClick:
                        onButtonDoubleClicked.Invoke();
                        break;
                    case Move.Feedback.TripleClick:
                        onButtonTrippleClicked.Invoke();
                        break;
                    default:
                        Debug.LogError("Unknown Move.Feedback, save your logs and leave angery messages on the Discord.");
                        break;
                }
            }
        }

        private void OnDestroy()
        {
            try
            {
                if(_decaMove != null)
                {
                    _decaMove.Dispose();
                    _decaMove = null;
                }
            }
            catch (Exception e)
            {
                Debug.unityLogger.Log(LogType.Error, "Exception occured in DecaMoveBehaviour OnDestroy: " + e);
            }
        }

        public void SendHaptic()
        { 
            try
            {
                _decaMove.Value.SendHaptic();
            }
            catch (DecaSDK.Move.NativeCallFailedException e)
            {
                if (e.Status != DecaSDK.Move.Status.ErrorNotConnected)
                {
                    throw;
                }
            }
        }
        public void Calibrate()
        {
            try
            {
                Quaternion parentRotationOffset = Quaternion.identity;
                if (transform.parent)
                    parentRotationOffset = Quaternion.Inverse(transform.parent.rotation);
                Vector3 headForward = parentRotationOffset * head.forward;
                _decaMove.Value.Calibrate(headForward.z, headForward.x);
            }
            catch (DecaSDK.Move.NativeCallFailedException e)
            {
                if (e.Status != DecaSDK.Move.Status.ErrorNotConnected)
                {
                    throw;
                }
            }
        }

    }
}

