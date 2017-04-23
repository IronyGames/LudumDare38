#pragma once

#include "IGameState.h"

class GameStateGame: public IGameState {
public:
	String update() override;
	void draw() override;
};