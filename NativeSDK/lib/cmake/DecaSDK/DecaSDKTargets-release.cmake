#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "DecaSDK::native" for configuration "Release"
set_property(TARGET DecaSDK::native APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(DecaSDK::native PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/SDK/lib/deca_sdk.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/SDK/bin/deca_sdk.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS DecaSDK::native )
list(APPEND _IMPORT_CHECK_FILES_FOR_DecaSDK::native "${_IMPORT_PREFIX}/SDK/lib/deca_sdk.lib" "${_IMPORT_PREFIX}/SDK/bin/deca_sdk.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
