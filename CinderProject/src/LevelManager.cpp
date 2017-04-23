#include "LevelManager.h"
#include "GardenLogic.h"

LevelManager::LevelManager( std::vector<Level> levels_ )
	: levels( std::move(levels_ ))
{}

GardenVisual* LevelManager::getGardenVisual() const
{
	return levels[currentLevel].getGardenVisual();
}

void LevelManager::onTimeChanged( Year deltaYear )
{
	GardenLogic* gardenLogic = levels[currentLevel].getGardenLogic();
	gardenLogic->updateGardenTo(deltaYear);
}
