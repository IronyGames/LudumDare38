#include "LevelManager.h"
#include "GardenLogic.h"
#include "GardenVisual.h"
#include "PlantLogic.h"
#include "PlantVisual.h"
#include "InventoryLogic.h"

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

InventoryLogic* LevelManager::getInventory() const
{
	return levels[currentLevel].getInventory();
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

void LevelManager::onAddEntity( CoordsInt tile )
{
	GardenLogic* gardenLogic = getGardenLogic();
	const IGardenEntityLogic* entity = gardenLogic->getEntityAt(tile);
	if ( !entity )
	{
		boost::optional<EntityDef> selectedEntityDef = getInventory()->extractSelectedEntityDef();
		if (selectedEntityDef)
		{
			getGardenLogic()->plant( *selectedEntityDef, tile );
		}
	}
}

void LevelManager::onRemoveEntity( CoordsInt tile )
{
	const IGardenEntityLogic* entity = getGardenLogic()->getEntityAt(tile);
	if (entity && !entity->isStatic())
	{
		EntityDef entityDef = getGardenLogic()->unPlant( tile );
		getInventory()->addEntity( entityDef, 1);
	}
}
