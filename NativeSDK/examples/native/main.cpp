#include "move.h"

#include <Windows.h>

#include <thread>

int main(int ac, char** av) {
    struct Context {
        deca_move_state state = kDecaMoveStateClosed;
        bool isSleeping = true;
    } context;

    deca_move_callbacks callbacks = {};
    callbacks.feedback_cb = [](deca_move_feedback feedback, void* userData) {
        printf("Feedback: %d\n", int(feedback));
        if (feedback == kDecaMoveFeedbackEnteringSleep) {
            ((Context*)userData)->isSleeping = true;
        } else if (feedback == kDecaMoveFeedbackLeavingSleep) {
            ((Context*)userData)->isSleeping = false;
        }
    };
    callbacks.battery_update_cb = [](float charge, void* userData) {
        printf("Battery: %g%%\n", charge);
    };
    callbacks.orientation_update_cb = [](deca_move_quaternion quat, deca_move_accuracy accuracy, float yawCalibration, void* userData) {
        printf("Orientation: %.2f %.2f %.2f %.2f yaw=%.2f [%d]\n", quat.x, quat.y, quat.z, quat.w, yawCalibration, int(accuracy));
    };
    callbacks.position_update_cb = [](float position_x, float position_y, float position_z, void* userData) {
        printf("Position: %.2f %.2f %.2f\n", position_x, position_y, position_z);
    };
    callbacks.state_update_cb = [](deca_move_state state, void* userData) {
        ((Context*)userData)->state = state;
        printf("State: %d\n", state);
    };
    callbacks.user_data = &context;

    deca_move_env_desc envDesc = {};

    deca_move deca_move = nullptr;
    auto status = decaMoveInit(envDesc, callbacks, &deca_move);
    if (status == kDecaMoveStatusSuccess) {
        while (true) {
            if (GetKeyState('H') & 0x8000) {
                if (context.state == kDecaMoveStateClosed) {
                    printf("Cannot send haptic - deca move is not streaming\n");
                } else if (context.state != kDecaMoveStateStreaming && context.isSleeping) {
                    printf("Cannot send haptic - deca move is sleeping\n");
                } else {
                    if (context.state == kDecaMoveStateOpen) {
                        printf("Haptic send is not guaranteed - deca move is connected but not paired\n");
                    }
                    decaMoveSendHaptic(deca_move);
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(33));
        }
    }
    decaMoveRelease(deca_move);
    return 0;
}