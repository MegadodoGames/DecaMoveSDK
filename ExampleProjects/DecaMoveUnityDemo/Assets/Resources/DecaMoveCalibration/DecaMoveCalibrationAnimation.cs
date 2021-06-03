using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DecaMoveCalibrationAnimation : MonoBehaviour
{
    const int kNumAxes = 3;
    const float kAxisAnimationDuration = 5;
    public const float kTotalAnimationDuration = kNumAxes * kAxisAnimationDuration;

    float _animationTime;
    void Start()
    {
        _animationTime = 0;
    }
    void Update()
    {
        _animationTime = (_animationTime + Time.deltaTime) % kTotalAnimationDuration;

        int axisIdx = (int)(_animationTime / kAxisAnimationDuration);
        float progress = (_animationTime % kAxisAnimationDuration) / kAxisAnimationDuration;

        const int kNumRepeats = 2;
        progress = (progress * kNumRepeats) % 1.0f;

        const float kHoldDuration = 0.1f;
        progress = Mathf.Clamp01((progress - kHoldDuration) / (1.0f - 2.0f * kHoldDuration));

        progress = 1.0f - 2.0f * Mathf.Abs(progress - 0.5f);

        Vector3 eulerAngles = new Vector3();
        eulerAngles[axisIdx] = progress * 180.0f;

        transform.rotation = Quaternion.Euler(eulerAngles);
    }
}
