using System;
using UnityEngine;
using DecaSDK.Unity;

public class BatteryTextController : MonoBehaviour
{
    private TextMesh _textMesh;
    private SharedDisposable<SharedMove> _decaMove;

    private DecaSDK.Move.Accuracy _accuracy;
    private float _batteryCharge;
    private DecaSDK.Move.State _state;
    private DecaSDK.Move.Feedback _feedback;
    private DateTime _feedbackTime;
    private TimeSpan _feedbackTimeout = TimeSpan.FromSeconds(1);

    // Start is called before the first frame update
    void Start()
    {
        _textMesh = GetComponent<TextMesh>();

        try
        {
            _decaMove = SharedMove.Instance;
            _decaMove.Value.AddCallbacks(OnDecaMoveFeedback, OnDecaMoveBatteryUpdate, OnDecaMoveOrientationUpdate, null, OnDecaMoveStateUpdate, null, null);
        }
        catch (DecaSDK.Move.NativeCallFailedException e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
        catch (Exception e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
    }

    // Update is called once per frame
    void Update()
    {
        DecaSDK.Move.Accuracy accuracy;
        DecaSDK.Move.State state;
        float batteryCharge;
        string feedbackStr;

        lock (this)
        {
            if (DateTime.Now - _feedbackTime > _feedbackTimeout)
            {
                feedbackStr = "none";
            }
            else
            {
                feedbackStr = _feedback.ToString();
            }

            batteryCharge = _batteryCharge;
            accuracy = _accuracy;
            state = _state;
        }

        var text = "";
        text += $"State: {state.ToString()}\n";
        text += $"Feedback: {feedbackStr}\n";
        text += $"Battery: {batteryCharge}\n";
        text += $"Accuracy: {accuracy}";
        _textMesh.text = text;
    }
    void OnDecaMoveFeedback(DecaSDK.Move.Feedback feedback)
    {
        lock (this)
        {
            _feedback = feedback;
            _feedbackTime = DateTime.Now;
        }
    }
    void OnDecaMoveBatteryUpdate(float charge)
    {
        lock (this)
        {
            _batteryCharge = charge;
        }
    }
    void OnDecaMoveStateUpdate(DecaSDK.Move.State state)
    {
        lock (this)
        {
            _state = state;
        }
    }
    void OnDecaMoveOrientationUpdate(DecaSDK.Move.Quaternion quat, DecaSDK.Move.Accuracy accuracy, float yawDrift)
    {
        lock (this)
        {
            _accuracy = accuracy;
        }
    }
}
