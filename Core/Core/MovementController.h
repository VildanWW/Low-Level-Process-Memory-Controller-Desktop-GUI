#pragma once
#include "BaseFunctional.h"

class MovementController : public BaseFunctional {
public:
    typedef unsigned int(__fastcall* t_MoveHandler)(char param_1);
    
    static inline t_MoveHandler o_moveHandler = nullptr;

    static unsigned int __fastcall hk_moveHandler(char param_1);

    void Initialize() override;
    void ShutDown() override;
};
