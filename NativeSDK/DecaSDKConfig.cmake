get_filename_component(DECASDK_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(CMakeFindDependencyMacro)

if(NOT TARGET DecaSDK::DecaSDK)
    include("${DECASDK_CMAKE_DIR}/lib/cmake/DecaSDK/DecaSDKTargets.cmake")

    add_library(deca_sdk_dotnet INTERFACE)
    target_sources(deca_sdk_dotnet INTERFACE ${DECASDK_CMAKE_DIR}/dotnet/DecaSDK.cs)
    add_library(DecaSDK::dotnet ALIAS deca_sdk_dotnet)
endif()
