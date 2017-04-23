#pragma once

#include "Typedef.h"

class IGameState{
public:
	virtual ~IGameState() = default;
	virtual String update() = 0;
	virtual void draw() = 0;
};