#ifndef DECA_SDK_UNREAL_H
#define DECA_SDK_UNREAL_H

#include "move.h"

/** @brief Convert quaternion from deca move space to unreal engine space.
 *
 *  @param quaternion       Quaternion from deca_move_on_orientation_update_callback_t
 */
inline FQuat decaMoveToUE(deca_move_quaternion q) {
    return FQuat(q.y, q.x, q.w, q.z) * FRotator(90, 0, 0).Quaternion();
}

#endif // DECA_SDK_UNREAL_H
