#ifndef DECA_SDK_API_H
#define DECA_SDK_API_H

#define DECA_SDK_VERSION_MAJOR 0
#define DECA_SDK_VERSION_MINOR 0
#define DECA_SDK_VERSION_REVISION 1 

#if defined(_WIN32) || defined(_WIN64)
# define DECA_OS_WINDOWS
#elif defined(__ANDROID__)
# define DECA_OS_ANDROID
#else
# error "Unsupported platform"
#endif

#if defined(_MSC_VER)
# define DECA_COMPILER_MSVC
#elif defined(__clang__)
# define DECA_COMPILER_CLANG
#else
# error "Unsupported compiler"
#endif

#if defined(DECA_OS_WINDOWS)
# if defined(DECA_COMPILER_MSVC)
#  define DECA_EXPORT __declspec(dllexport)
#  define DECA_IMPORT __declspec(dllimport)
#  define DECA_HIDDEN
# else
#  define DECA_EXPORT __attribute__((dllexport))
#  define DECA_IMPORT __attribute__((dllimport))
#  define DECA_HIDDEN
# endif
#else
# define DECA_EXPORT __attribute__((visibility("default")))
# define DECA_IMPORT
# define DECA_HIDDEN __attribute__((visibility("hidden")))
#endif

#if defined(DECA_SDK_HIDDEN)
# define DECA_SDK_API DECA_HIDDEN
#elif defined(DECA_SDK_EXPORTS)
# define DECA_SDK_API DECA_EXPORT
#else
# define DECA_SDK_API DECA_IMPORT
#endif

#endif // DECA_SDK_API_H
