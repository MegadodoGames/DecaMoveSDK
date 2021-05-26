using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DecaSDK.Unity;

public class DecaMoveOverlay : MonoBehaviour
{
    private SharedDisposable<SharedMove> _decaMove;
    private DecaSDK.Move.State _decaMoveState;
    private bool _isDecaMoveSleeping;
    private Quaternion _overlayRotation;
    private SpriteRenderer _spriteRenderer;

    // Start is called before the first frame update
    void Start()
    {
        _spriteRenderer = GetComponent<SpriteRenderer>();

        transform.localScale = new Vector3(0.1f, 0.1f, 0.1f);

        _decaMoveState = DecaSDK.Move.State.Closed;
        _isDecaMoveSleeping = false;

        try
        {
            _decaMove = SharedMove.Instance;
            _decaMove.Value.AddCallbacks(OnDecaMoveFeedback, null, OnDecaMoveOrientationUpdate, null, OnDecaMoveStateUpdate, null);
        }
        catch (DecaSDK.Move.NativeCallFailedException e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
        catch (System.Exception e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
    }
    // Update is called once per frame
    void Update()
    {
        bool isDecaMoveSleeping;
        Quaternion overlayRotation;
        DecaSDK.Move.State decaMoveState;
        lock (this)
        {
            isDecaMoveSleeping = _isDecaMoveSleeping;
            overlayRotation = _overlayRotation;
            decaMoveState = _decaMoveState;
        }

        if (decaMoveState == DecaSDK.Move.State.Streaming &&
            !isDecaMoveSleeping)
        {
            _spriteRenderer.enabled = true;

            var currentCamera = Camera.current;
            if (currentCamera != null)
            {
                transform.position = currentCamera.transform.position - new Vector3(0.0f, 0.75f, 0.0f);
            }
            transform.rotation = overlayRotation;
        }
        else
        {
            _spriteRenderer.enabled = false;
        }
    }
    public static float SignedAngleFromTo(Vector2 a, Vector2 b)
    {
        return Mathf.Atan2(a.x * b.y - a.y * b.x, a.x * b.x + a.y * b.y);
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
    }
    void OnDecaMoveOrientationUpdate(DecaSDK.Move.Quaternion quaternion, DecaSDK.Move.Accuracy accuracy, float yawCalibration)
    {
        var quat = quaternion.ToUnity();
        quat = quat * (new Quaternion(0, 0, 1, 0)) * (new Quaternion(-quat.x, -quat.y, -quat.z, quat.w));
        Vector2 hipForward = new Vector2(quat.z, quat.x);
        hipForward.Normalize();

        var sinTheta = Mathf.Sin(yawCalibration);
        var cosTheta = Mathf.Cos(yawCalibration);
        var xr = cosTheta * hipForward.x - sinTheta * hipForward.y;
        var yr = sinTheta * hipForward.x + cosTheta * hipForward.y;
        hipForward.x = xr;
        hipForward.y = yr;

        float hipAngle = SignedAngleFromTo(new Vector2(1.0f, 0.0f), hipForward) * Mathf.Rad2Deg;

        var modelQuat = Quaternion.AngleAxis(90.0f, Vector3.right);

        lock (this)
        {
            _overlayRotation = Quaternion.Euler(0, hipAngle, 0) * modelQuat;
        }
    }
    void OnDecaMoveStateUpdate(DecaSDK.Move.State state)
    {
        lock (this)
        {
            _decaMoveState = state;
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
}
