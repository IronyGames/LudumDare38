#include "GameStateManager.h"
#include "IGameState.h"

GameStateManager::GameStateManager(std::map<String, IGameState*> _states, String _initialState)
: states(_states)
, currentState(nullptr)
{
	changeState(_initialState);
}

void GameStateManager::changeState(String _state)
{
	if (currentState != nullptr){
		currentState->deactivate();
	}
	currentState = states[_state];
	currentState->activate();
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
