using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BindToCamera : MonoBehaviour
{
    private Bounds _bounds;
    void Start()
    {
        _bounds = new Bounds(Vector3.zero, Vector3.zero);
        foreach (Renderer r in GetComponentsInChildren<Renderer>())
        {
            _bounds.Encapsulate(r.bounds);
        }
    }
    void Update()
    {
        Camera camera = Camera.current;
        if (camera)
        {
            const float localPosZ = 0.6f;

            float requiredHeight = 2.0f * localPosZ * Mathf.Tan(camera.fieldOfView * 0.5f * Mathf.Deg2Rad);
            float requiredWidth = 0.2f * requiredHeight * camera.aspect;
            float scale = requiredWidth / _bounds.size[1];

            transform.SetParent(camera.transform);
            transform.localPosition = Vector3.forward * localPosZ - Vector3.up * (scale * _bounds.size[1] * 0.25f);
            transform.localRotation = Quaternion.identity;
            transform.localScale = new Vector3(scale, scale, scale);
        }
    }
}
