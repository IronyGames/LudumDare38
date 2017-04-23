#include "LevelManager.h"
#include "GardenLogic.h"
#include "PlantLogic.h"
#include "PlantVisual.h"

LevelManager::LevelManager( std::vector<Level> levels_ )
	: levels( std::move(levels_ ))
{}

GardenVisual* LevelManager::getGardenVisual() const
{
	return levels[currentLevel].getGardenVisual();
}

GardenLogic* LevelManager::getGardenLogic() const
{
	return levels[currentLevel].getGardenLogic();
}

void LevelManager::onTimeChanged( Year deltaYear )
{
	GardenLogic* gardenLogic = getGardenLogic();
	gardenLogic->updateGardenDelta(deltaYear);
}

void LevelManager::onLeftMouse( CoordsInt mousePosition )
{
	CoordsInt clickedTile = getTile(mousePosition);
	PlantLogic *nextSeed = new PlantLogic(GardenEntityPattern(), Year(300), clickedTile);
	getGardenLogic()->addEntity(nextSeed);
}

void LevelManager::onRightMouse( CoordsInt mousePosition )
{
	CoordsInt clickedTile = getTile(mousePosition);
	getGardenLogic()->unPlant(clickedTile);
}

CoordsInt LevelManager::getTile(CoordsInt mousePosition)
{
	return CoordsInt(1, 1);
}
