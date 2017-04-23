#pragma once

#include "Typedef.h"

class IGameState{
public:
	virtual String update() = 0;
	virtual void draw() = 0;
};