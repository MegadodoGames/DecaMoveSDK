cmake_minimum_required(VERSION 3.14)

PROJECT(DecaSDK_Test VERSION 0.0.1.0 LANGUAGES CXX CSharp)

if(NOT TARGET DecaSDK::native)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/..)
    find_package(DecaSDK REQUIRED)
endif()

add_subdirectory(native)
add_subdirectory(dotnet)
