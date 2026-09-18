#pragma once
#include "BaseFunctional.h"

class MovementController : public BaseFunctional {
public:
    typedef unsigned int(__fastcall* t_MoveHandler)(char param_1);
    static inline t_MoveHandler o_MoveHandler = nullptr;
    static unsigned int __fastcall hk_MoveHandler(char param_1);

    typedef void(__stdcall* t_RotationHandler)(float* param_1);
    static inline t_RotationHandler o_RotationHandler = nullptr;
    static void __stdcall hk_RotationHandler(float* param_1);
     
    void Initialize() override;
    void ShutDown() override;
};