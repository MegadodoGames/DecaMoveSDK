using UnityEngine;
using DecaSDK.Unity;

public class DecaMoveController : MonoBehaviour
{
    private SharedDisposable<SharedMove> _decaMove;
    private DecaSDK.Move.State _decaMoveState;
    private bool _isDecaMoveSleeping;
    private Quaternion _decaMoveQuaternion;
    private Vector3 _decaMovePosition;
    private MeshRenderer _meshRenderer;

    private void Start()
    {
        _decaMoveState = DecaSDK.Move.State.Closed;
        _isDecaMoveSleeping = false;

        var mesh = GetComponent<MeshFilter>().mesh;
        var bounds = mesh.bounds;
        const float kRealDeviceXSize = 0.058f; // in meters
        float scale = kRealDeviceXSize / bounds.size.x;
        transform.localScale = new Vector3(scale, scale, scale);

        _meshRenderer = GetComponent<MeshRenderer>();
        _meshRenderer.enabled = false;

        try
        {
            _decaMove = SharedMove.Instance;
            _decaMove.Value.AddCallbacks(OnDecaMoveFeedback, OnDecaMoveBatteryUpdate, OnDecaMoveOrientationUpdate, OnDecaMovePositionUpdate, OnDecaMoveStateUpdate, null, OnDecaMoveLogMessage);
        }
        catch (DecaSDK.Move.NativeCallFailedException e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
        catch (System.Exception e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
        _decaMoveQuaternion = new Quaternion();
    }
    void Update()
    {
        if (_decaMove == null)
        {
            return;
        }

        DecaSDK.Move.State decaMoveState;
        Quaternion decaMoveQuaternion;
        Vector3 decaMovePosition;
        bool isDecaMoveSleeping;
        lock (this)
        {
            decaMoveState = _decaMoveState;
            decaMoveQuaternion = _decaMoveQuaternion;
            decaMovePosition = _decaMovePosition;
            isDecaMoveSleeping = _isDecaMoveSleeping;
        }

        if (decaMoveState == DecaSDK.Move.State.Closed ||
            isDecaMoveSleeping)
        {
            _meshRenderer.enabled = false;
        }
        else
        {
            _meshRenderer.enabled = true;

            var currentCamera = Camera.current;

            if (decaMoveState == DecaSDK.Move.State.Streaming)
            {
                ProcessHaptic();
                ProcessCalibration();

                transform.rotation = _decaMoveQuaternion;
                if (currentCamera != null)
                {
                    transform.position = currentCamera.transform.position + _decaMovePosition;
                }
            }
            else
            {
                transform.rotation = Quaternion.identity;
                if (currentCamera != null)
                {
                    transform.position = currentCamera.transform.position - new Vector3(0, 0.75f, 0);
                }
            }
        }
    }
    private void ProcessHaptic()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            try
            {
                _decaMove.Value.SendHaptic();
            }
            catch (DecaSDK.Move.NativeCallFailedException e)
            {
                Debug.LogError($"Failed to send haptic: {e.Message}");
            }
        }
    }
    private void ProcessCalibration()
    {
        if (Input.GetKeyDown(KeyCode.C))
        {
            try
            {
                Camera camera = (Camera)FindObjectOfType(typeof(Camera));
                if (camera)
                {
                    var fwd = camera.transform.forward;
                    _decaMove.Value.Calibrate(fwd.x, fwd.z);
                }
                else
                {
                    Debug.LogError("Cannot calibrate: no camera");
                }
            }
            catch (DecaSDK.Move.NativeCallFailedException e)
            {
                Debug.LogError($"Failed to calibrate: {e.Message}");
            }
        }
    }
    void OnApplicationQuit()
    {
        if (_decaMove != null)
        {
            _decaMove.Dispose();
            _decaMove = null;
        }
    }
    private void OnDestroy()
    {
        if (_decaMove != null)
        {
            _decaMove.Dispose();
            _decaMove = null;
        }
    }
    void OnDecaMoveFeedback(DecaSDK.Move.Feedback feedback)
    {
        lock (this)
        {
            if (feedback == DecaSDK.Move.Feedback.EnteringSleep)
            {
                _isDecaMoveSleeping = true;
            }
            else if (feedback == DecaSDK.Move.Feedback.LeavingSleep)
            {
                _isDecaMoveSleeping = false;
            }
        }
        Debug.Log($"Feedback: {feedback}");
    }
    void OnDecaMoveBatteryUpdate(float charge)
    {
        Debug.Log($"Battery charge: {charge}");
    }
    void OnDecaMoveOrientationUpdate(DecaSDK.Move.Quaternion quaternion, DecaSDK.Move.Accuracy accuracy, float yawCalibration)
    {
        var q = UnityEngine.Quaternion.Euler(90, 0, 0); // model rotation - align up
        q = quaternion.ToUnity() * q;
        q = Quaternion.Euler(0, yawCalibration * Mathf.Rad2Deg, 0) * q;

        lock (this)
        {
            _decaMoveQuaternion = q;
        }
    }
    void OnDecaMovePositionUpdate(float x, float y, float z)
    {
        lock (this)
        {
            _decaMovePosition = new Vector3(x, y, z);
        }
    }
    void OnDecaMoveStateUpdate(DecaSDK.Move.State state)
    {
        lock (this)
        {
            _decaMoveState = state;
        }
        Debug.Log($"State: {state}");
    }
    void OnDecaMoveLogMessage(DecaSDK.Move.LogLevel logLevel, string message)
    {
        LogType unityLogType = ToUnity(logLevel);
        Debug.unityLogger.Log(unityLogType, message);
    }
    private LogType ToUnity(DecaSDK.Move.LogLevel logLevel)
    {
        switch (logLevel)
        {
            case DecaSDK.Move.LogLevel.Warn:
                return UnityEngine.LogType.Warning;
            case DecaSDK.Move.LogLevel.Err:
            case DecaSDK.Move.LogLevel.Critical:
                return UnityEngine.LogType.Error;
            default:
                return UnityEngine.LogType.Log;
        }
    }
}
