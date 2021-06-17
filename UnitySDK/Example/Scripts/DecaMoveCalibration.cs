/*
 * I know right now it's just a button, but if you want me to code in the logic 
 * for the calibration pose here, just send angry things to me (@WireWhiz) on the discord: https://discord.gg/9AQnUhZRt7 
 * 
 * (Ok, please try to be nice, but I am the one to send things to if you are angry.)
 */


using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
#endif

namespace DecaSDK
{
    public class DecaMoveCalibration : MonoBehaviour
    {
        DecaMoveBehaviour decaMove;
        void Start()
        {
            decaMove = GetComponent<DecaMoveBehaviour>();
        }
        public void Calibrate()
        {
            decaMove.Calibrate();
        }
    }
#if UNITY_EDITOR
    [CustomEditor(typeof(DecaMoveCalibration))]
    public class DecaMoveCalibrationEditor : Editor
    {
        public override void OnInspectorGUI()
        {
            base.OnInspectorGUI();
            if (GUILayout.Button("Calibrate"))
            {
                ((DecaMoveCalibration)target).Calibrate();
            }
        }
    }
#endif

}
