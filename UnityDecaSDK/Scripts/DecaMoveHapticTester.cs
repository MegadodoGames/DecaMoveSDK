using System.Collections;
using System.Collections.Generic;
using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
#endif

namespace DecaSDK
{
    public class DecaMoveHapticTester : MonoBehaviour
    {
        DecaMoveBehaviour decaMove;
        void Start()
        {
            decaMove = GetComponent<DecaMoveBehaviour>();
        }

        public void SendHaptic()
        {
            // This is an example of how to activate the haptics on the DecaMove,
            // This was essental to demonstrate as it's very hard and 
            // only master coders can manage it from scratch, so I did it for you.
            // Feel free to copy and paste.
            decaMove.SendHaptic();
        }
    }

#if UNITY_EDITOR
    [CustomEditor(typeof(DecaMoveHapticTester))]
    public class DecaMoveHapticTesterEditor : Editor
    {
        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();
            if(GUILayout.Button("Send haptic pulse"))
            {
                ((DecaMoveHapticTester)target).SendHaptic();
            }
        }
    }
#endif
    }
