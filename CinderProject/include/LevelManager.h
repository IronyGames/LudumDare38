#pragma once
#include "InputController.h"
#include "Level.h"
#include <vector>

class LevelManager : public EventListener
{
public:
	LevelManager( std::vector<Level> levels_ );

	GardenVisual* getGardenVisual() const;

private:
	// EventListener
	void onTimeChanged( Year deltaYear ) override;
  
	std::vector<Level> levels;
	size_t currentLevel = 0;
};