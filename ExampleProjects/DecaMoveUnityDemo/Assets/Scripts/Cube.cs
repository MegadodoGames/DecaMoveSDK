using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DecaSDK.Unity;

public class Cube : MonoBehaviour
{
    private SharedDisposable<SharedMove> _decaMove;
    private Quaternion _rotation;

    void Start()
    {
        Mesh mesh = GetComponent<MeshFilter>().mesh;
        Vector2[] UVs = new Vector2[mesh.vertices.Length];
        // Front
        UVs[0] = new Vector2(0.0f, 0.0f);
        UVs[1] = new Vector2(0.333f, 0.0f);
        UVs[2] = new Vector2(0.0f, 0.333f);
        UVs[3] = new Vector2(0.333f, 0.333f);
        // Top
        UVs[4] = new Vector2(0.334f, 0.333f);
        UVs[5] = new Vector2(0.666f, 0.333f);
        UVs[8] = new Vector2(0.334f, 0.0f);
        UVs[9] = new Vector2(0.666f, 0.0f);
        // Back
        UVs[6] = new Vector2(1.0f, 0.0f);
        UVs[7] = new Vector2(0.667f, 0.0f);
        UVs[10] = new Vector2(1.0f, 0.333f);
        UVs[11] = new Vector2(0.667f, 0.333f);
        // Bottom
        UVs[12] = new Vector2(0.0f, 0.334f);
        UVs[13] = new Vector2(0.0f, 0.666f);
        UVs[14] = new Vector2(0.333f, 0.666f);
        UVs[15] = new Vector2(0.333f, 0.334f);
        // Left
        UVs[16] = new Vector2(0.334f, 0.334f);
        UVs[17] = new Vector2(0.334f, 0.666f);
        UVs[18] = new Vector2(0.666f, 0.666f);
        UVs[19] = new Vector2(0.666f, 0.334f);
        // Right        
        UVs[20] = new Vector2(0.667f, 0.334f);
        UVs[21] = new Vector2(0.667f, 0.666f);
        UVs[22] = new Vector2(1.0f, 0.666f);
        UVs[23] = new Vector2(1.0f, 0.334f);
        mesh.uv = UVs;

        try
        {
            _decaMove = SharedMove.Instance;
            _decaMove.Value.AddCallbacks(null, null,
                (quat, accuracy, calibration) =>
                {
                    lock (this)
                    {
                        _rotation = Quaternion.Euler(0, calibration * Mathf.Rad2Deg, 0) * quat.ToUnity();
                    }
                },
                null, null, null);
        }
        catch (DecaSDK.Move.NativeCallFailedException e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
        catch (System.Exception e)
        {
            Debug.LogError($"Failed to initialize DecaMove: {e.Message}");
        }
        _rotation = new Quaternion();
    }

    // Update is called once per frame
    void Update()
    {
        lock (this)
        {
            transform.rotation = _rotation;
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
