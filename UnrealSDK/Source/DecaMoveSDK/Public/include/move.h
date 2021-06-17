#ifndef DECA_SDK_MOVE_H
#define DECA_SDK_MOVE_H

#include "api.h"

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

/**************************************** Enums *******************************************/

typedef enum // deca_move_state
{
    /// Disconnected from the USB port or the port is not open
    kDecaMoveStateClosed = 0,

    /// Connected to the USB port, port is open, but idle.
    /// There are no quaternion messages streaming from DecaMove.
    kDecaMoveStateOpen,

    /// Connected to the USB port, port is open, but idle.
    /// DecaMove is paired to dongle (probably in sleep or calibration state),
    /// but not streaming quaternion.
    kDecaMoveStatePaired,

    /// Connected to the USB port, port is open, and active.
    /// There are quaternion messages streaming from DecaMove.
    kDecaMoveStateStreaming,
} deca_move_state;

typedef enum // deca_move_status
{
    kDecaMoveStatusSuccess = 0,
    kDecaMoveStatusErrorDataPort,
    kDecaMoveStatusErrorNotConnected,
    kDecaMoveStatusErrorNotImplemented,
    kDecaMoveStatusErrorUnknown, // report to developers
} deca_move_status;

typedef enum // deca_move_feedback
{
    kDecaMoveFeedbackEnteringSleep = 0,
    kDecaMoveFeedbackLeavingSleep,
    kDecaMoveFeedbackShuttingDown,
    kDecaMoveFeedbackSingleClick,
    kDecaMoveFeedbackDoubleClick,
    kDecaMoveFeedbackTripleClick,
} deca_move_feedback;

typedef enum // deca_move_accuracy
{
    kDecaMoveAccuracyUnreliable,
    kDecaMoveAccuracyLow,
    kDecaMoveAccuracyMedium,
    kDecaMoveAccuracyHigh,
    kDecaMoveAccuracyUnspecified
} deca_move_accuracy;

typedef enum // deca_move_env_flag
{
    kDecaMoveEnvComLib = 1 << 0, // Hosting application controls COM library lifetime
} deca_move_env_flag;

typedef enum // deca_move_env_log_level
{
    kDecaMoveEnvLogLevelTrace,
    kDecaMoveEnvLogLevelDebug,
    kDecaMoveEnvLogLevelInfo,
    kDecaMoveEnvLogLevelWarn,
    kDecaMoveEnvLogLevelErr,
    kDecaMoveEnvLogLevelCritical,
} deca_move_env_log_level;

/**************************************** Types *******************************************/

typedef struct deca_move_t { void*_; } * deca_move;

#pragma pack(push, 8)

typedef struct // deca_move_quaternion
{
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float array[4];
    };
} deca_move_quaternion;

typedef void (*deca_move_env_log_callback_t)(deca_move_env_log_level, const char* message, void* user_data);

/// Describes host application environment
typedef struct // deca_move_env_desc
{
    /// deca_move_env_flag
    uint32_t flags;
    deca_move_env_log_callback_t log_callback;
    void* log_user_data;
} deca_move_env_desc;

typedef void (*deca_move_on_feedback_callback_t)(deca_move_feedback, void* user_data);
typedef void (*deca_move_on_battery_update_callback_t)(float charge, void* user_data);
typedef void (*deca_move_on_orientation_update_callback_t)(deca_move_quaternion, deca_move_accuracy, float yaw_drift, void* user_data);
typedef void (*deca_move_on_position_update_callback_t)(float position_x, float position_y, float position_z, void* user_data);
typedef void (*deca_move_on_state_update_callback_t)(deca_move_state, void* user_data);
typedef void (*deca_move_on_imu_calibration_request_callback_t)(void* user_data);

typedef struct {
    void* user_data;

    /// See @ref deca_move_feedback.
    deca_move_on_feedback_callback_t feedback_cb;

    /// The battery charge is in percentages, with precision up to the first decimal.
    deca_move_on_battery_update_callback_t battery_update_cb;

    /// Orientation is in the right-hand side coordinate system with X pointing up.
    deca_move_on_orientation_update_callback_t orientation_update_cb;

    /// The approximate position of the device in HMD local space.
    deca_move_on_position_update_callback_t position_update_cb;

    /// See @ref deca_move_state.
    deca_move_on_state_update_callback_t state_update_cb;

    /// Called by the deca move when it detects the need of IMU calibration.
    /// See @ref decaMoveStartImuCalibration for more information.
    deca_move_on_imu_calibration_request_callback_t imu_calibration_request_cb;
} deca_move_callbacks;
#pragma pack(pop)

/**************************************** Functions ***************************************/

/** @brief Initialize the Deca Move device
 *
 *  Description. Possible error codes for this call are:
 *
 *     kDecaMoveError_
 *
 *  @param env         A Deca Move environment descriptor
 *  @param callbacks
 *  @param out_context Pointer to a Deca Move object
 *  @return                                kDecaMoveSuccess in case of success, error code otherwise
 */
DECA_SDK_API deca_move_status decaMoveInit(
    deca_move_env_desc env_desc,
    deca_move_callbacks callbacks,
    deca_move* out_deca_move);

/** @brief Requests the Deca Move device to vibrate
 *
 *  TODO: Describe the current haptic work pecularities (e.g. maximum frequency)
 *
 *  @param deca_move       Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveSendHaptic(deca_move deca_move);

/** @brief Requests the Deca Move device to stop vibrating
 *
 *  @param deca_move       Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveStopHaptic(deca_move deca_move);

/** @brief Requests the Deca Move device to blink with its LED
 *
 *  @param duration_seconds   Duration must be in range [1; 30]
 *  @param frequency          Frequency must be in range [1; 20]
 *  @param deca_move          Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveSendBlink(deca_move deca_move, int duration_seconds, int frequency);

/** @brief Update the yaw drift sent in deca_move_on_calibrated_orientation_update_callback_t according to the forward direction.
 *
 *  @param deca_move            Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveCalibrate(deca_move deca_move, float forwardX, float forwardY);

/** @brief Starts inertial measurement unit (IMU) calibration process.
 *
 *  To calibrate the DecaMove, you will need to rotate it ~180° and back to the beginning position in each axis (pitch, yaw, roll).
 *  To stop calibration process use either @ref decaMoveStopImuCalibration or @ref decaMoveAbortImuCalibration.
 *
 *  @param deca_move            Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveStartImuCalibration(deca_move deca_move);

/** @brief Stops IMU calibration process and saves calibration results.
 *
 *  @param deca_move            Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveStopImuCalibration(deca_move deca_move);

/** @brief Stops IMU calibration process and discards calibration results.
 *
 *  @param deca_move            Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API deca_move_status decaMoveAbortImuCalibration(deca_move deca_move);

/** @brief Release the Deca Move device
 *
 *  Releases all resources associated with the Deca Move device.
 *
 *  @param deca_move       Pointer to the Deca Move object created with @ref decaMoveInit.
 */
DECA_SDK_API void decaMoveRelease(deca_move deca_move);

// /** @brief Release the Deca Move device
//  *
//  *  Releases all resources associated with the Deca Move device.
//  *
//  *  @param deca_move       Pointer to the Deca Move object created with @ref decaMoveInit.
//  */
// DECA_SDK_API deca_move_status decaMoveGetFirmwareVersion(deca_move deca_move, );

#ifdef __cplusplus
}
#endif

#endif // DECA_SDK_MOVE_H
