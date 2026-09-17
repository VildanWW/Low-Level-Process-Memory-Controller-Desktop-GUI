#pragma once
#include "BaseFunctional.h"

class BaseFunctional {
public:
	virtual void Initialize() = 0;
	virtual void ShutDown() = 0;

	virtual ~BaseFunctional() = default;
};