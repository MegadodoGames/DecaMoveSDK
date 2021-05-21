# DecaSDK

DecaSDK allows you to use the Deca Move device in your Native/Unreal/Unity projects on Windows and Oculus.

## Usage

### Native (Unreal)

The only public header that you need to include to use is `include/deca/move.h`. Link your project against `lib/deca_sdk.lib`. And make sure `deca_sdk.dll` is in PATH, or in your working directory, or located in the same directory as executable.

For a basic example of the usage please see `examples/native/main.cpp`.

Notes:

* All callbacks are coming from background threads.
* If your application initializes COM library, you need to specify this explicitly in `deca_move_env_desc`.

### C# (Unity)

Add `bin/deca_sdk.dll` and `dotnet/DecaSDK.cs` (P/Invoke wrapper) into your project.

For a basic example of the usage please see `examples/dotnet/Main.cs`.

Notes:

* `DecaSDK.Move` implements `IDisposable` interface because it allocates unmanaged resources. Make sure you call `Dispose()` when you are done with the Deca Move.
* All callbacks are coming from background threads.
