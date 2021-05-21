include(CSharpUtilities)

add_executable(deca_sdk_test_dotnet Main.cs)
target_link_libraries(deca_sdk_test_dotnet PRIVATE DecaSDK::dotnet)

set_property(TARGET deca_sdk_test_dotnet PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.6.1")
