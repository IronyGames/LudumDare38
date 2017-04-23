#include "GameStateManager.h"
#include "IGameState.h"

GameStateManager::GameStateManager(std::map<String, IGameState*> _states, String _initialState)
: states(_states)
{
	changeState(_initialState);
}

void GameStateManager::changeState(String _state)
{
	currentState = states[_state];
}

void GameStateManager::update()
{
	String result = currentState->update();
	if (result != ""){
		changeState(result);
	}
}

void GameStateManager::draw()
{
	currentState->draw();
}
