#pragma once

#include <map>
#include "Typedef.h"

class IGameState;

class GameStateManager{
public:
	GameStateManager(std::map<String, IGameState*> _states, String _initialState);
	void changeState(String _state);
	void update();
	void draw();
private:
	std::map<String, IGameState*> states;
	IGameState* currentState;
};