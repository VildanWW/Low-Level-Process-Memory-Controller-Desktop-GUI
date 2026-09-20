#pragma once
#include "BaseFunctional.h"
#include "Hotkeys.h"
#include "Offsets.h"

class MovementController : public BaseFunctional {
private:
    typedef unsigned int(__fastcall* t_MoveHandler)(const char param_1);
    static inline t_MoveHandler o_MoveHandler = nullptr;
    static unsigned int __fastcall hk_MoveHandler(const char param_1);

    typedef unsigned int(__cdecl* t_ScreenFadeMsg)(const char* param_1,int param_2, const unsigned char* param_3);
    static inline t_ScreenFadeMsg o_ScreenHandler = nullptr;
    static unsigned int __cdecl hk_ScreenHandler(const char* param_1, int param_2, const unsigned char* param_3);

    //typedef void(__stdcall* t_RotationHandler)(float* param_1);
    //static inline t_RotationHandler o_RotationHandler = nullptr;
    //static void __stdcall hk_RotationHandler(float* param_1);

    void Initialize() override;
    void ShutDown() override;
};