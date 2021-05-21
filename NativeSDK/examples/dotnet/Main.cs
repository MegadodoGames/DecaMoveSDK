using System;
using System.Threading;

namespace DecaSDK_Test
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                DecaSDK.Move.State moveState = DecaSDK.Move.State.Closed;

                DecaSDK.Move.OnFeedbackDelegate OnFeedback = (feedback) =>
                {
                    Console.WriteLine("Feedback: " + feedback);
                };
                DecaSDK.Move.OnBatteryUpdateDelegate OnBatteryUpdate = (charge) =>
                {
                    Console.WriteLine("Battery charge: " + charge);
                };
                DecaSDK.Move.OnOrientationUpdateDelegate OnOrientationUpdate = (quaternion, accuracy, yawCalibration) =>
                {
                    Console.WriteLine($"Orientation: {quaternion.x} {quaternion.y} {quaternion.z} {quaternion.w} yaw={yawCalibration} [{accuracy}]");
                };
                DecaSDK.Move.OnPositionUpdateDelegate OnPositionUpdate = (x, y, z) =>
                {
                    Console.WriteLine($"Position: {x} {y} {z}");
                };
                DecaSDK.Move.OnStateUpdateDelegate OnStateUpdate = (state) =>
                {
                    moveState = state;
                    Console.WriteLine($"Deca Move state: {state}");
                };
                DecaSDK.Move.OnLogMessage OnLogMessage = (logLevel, message) =>
                {
                    Console.WriteLine(message);
                };
                using (var decaMove = new DecaSDK.Move(OnFeedback, OnBatteryUpdate, OnOrientationUpdate, OnPositionUpdate, OnStateUpdate, OnLogMessage))
                {
                    while (true)
                    {
                        try
                        {
                            if (moveState != DecaSDK.Move.State.Closed)
                            {
                                decaMove.SendHaptic();
                            }
                        }
                        catch (DecaSDK.Move.NativeCallFailedException e)
                        {
                            if (e.Status != DecaSDK.Move.Status.ErrorNotConnected)
                            {
                                throw;
                            }
                        }
                        Thread.Sleep(4000);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception occured: " + e);
            }
        }
    }
}
