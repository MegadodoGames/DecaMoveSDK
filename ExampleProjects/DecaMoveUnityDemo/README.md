1. Generate DecaMoveUnitySDK package:

    `cd DecaHub/DecaMoveUnitySDK && python generatePackage.py`

2. Open the Unity project and play the game.

3. Startup DecaMoveService and enable DecaMove. Cube now must rotate synchronously to the device.

4. In order to move the sphere, use Python/pythonController.py:

    ```
    cd Python
    # create and activate virtual env (optional)
    python -m pip install requirements
    python pythonController.py
    ```
