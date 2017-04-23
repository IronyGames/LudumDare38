#include "LevelManager.h"
#include "GardenLogic.h"
#include "GardenVisual.h"
#include "PlantLogic.h"
#include "PlantVisual.h"

LevelManager::LevelManager(std::vector<Level> levels_ )
	: levels(std::move(levels_))
{
	selectLevel(0);
}

GardenVisual* LevelManager::getGardenVisual() const
{
	return levels[currentLevel].getGardenVisual();
}

GardenLogic* LevelManager::getGardenLogic() const
{
	return levels[currentLevel].getGardenLogic();
}

void LevelManager::selectLevel( unsigned level )
{
	currentLevel = level;
}

void LevelManager::onTimeChanged( Year deltaYear )
{
	GardenLogic* gardenLogic = getGardenLogic();
	gardenLogic->updateGardenDelta(deltaYear);

	GardenLogic::EvaluateGoalResult result = gardenLogic->evaluateGoal();
	assert( result.haveWon == false ); // oh now, you won
}

void LevelManager::onAddEntity( CoordsInt tile, IGardenEntityLogic* entity )
{
	if (tile == CoordsInt(-1, -1)){
		return;
	}
	getGardenLogic()->addEntity(entity);
}

void LevelManager::onRemoveEntity( CoordsInt tile )
{
	if (tile == CoordsInt(-1, -1)){
		return;
	}
	getGardenLogic()->unPlant(tile);
}
