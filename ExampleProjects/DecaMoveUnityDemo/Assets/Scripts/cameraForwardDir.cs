using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraForwardDir : MonoBehaviour
{
    private TMPro.TMP_Text cameraForwardDirText;
    // Start is called before the first frame update
    void Start()
    {
        foreach (var component in GetComponents<TMPro.TMP_Text>())
        {
            if (component.name == "cameraForwardDir")
            {
                cameraForwardDirText = component;
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (cameraForwardDirText != null)
        {
            Camera camera = (Camera)FindObjectOfType(typeof(Camera));
            if (camera)
            {
                var fwd = camera.transform.forward;
                cameraForwardDirText.text = $"camera: {fwd.x} {fwd.z}";
            }
        }
    }
}
