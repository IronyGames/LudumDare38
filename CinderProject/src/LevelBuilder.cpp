#include "LevelBuilder.h"
#include "LevelLoader.h"
#include "GardenInitializationData.h"
#include "PlantLogic.h"
#include "GardenLogic.h"
#include "IGardenGoalLogic.h"
#include "StaticGardenGoalLogic.h"
#include "InventoryLogic.h"

std::vector<Level> LevelBuilder::LoadLevels( std::string path )
{
	std::vector<Level> levels;

	LevelLoader levelLoader;
	std::vector<LevelData> levelsData = levelLoader.LoadLevelData( path );

	for(const auto& levelData : levelsData)
	{
		const GardenInitializationData& gardenInitializationData = levelData.gardenInitializationData;

		InventoryLogic* inventory = new InventoryLogic();
		for(const auto& kv : levelData.plantTypes)
		{
			std::string type = kv.first;
			const PlantData& plantData = kv.second;
			inventory->addEntity( EntityDef( plantData.pattern, type, false ), plantData.inventoryCount );
		}

		std::vector<IGardenEntityLogic*> gardenObjects;
		for(const auto& kv : gardenInitializationData.initialEntities)
		{
			CoordsInt coord = kv.first;
			GardenInitializationData::Entity plant = kv.second;

			auto it = levelData.plantTypes.find( plant.name );
			const PlantData& plantData = it->second;
			gardenObjects.emplace_back( new PlantLogic( EntityDef( plantData.pattern, plant.name, true ), plant.seedYear, plant.age, coord ) );
		}

		auto goals = BuildGoals( levelData.goals);
		GardenLogic* gardenLogic = new GardenLogic( gardenInitializationData.timeline, gardenInitializationData.gardenWidth, gardenInitializationData.gardenHeight, std::move(gardenObjects), goals );
		levels.emplace_back( Level( gardenLogic, inventory ) );
	}

	return levels;
}

IGardenGoalLogic* LevelBuilder::BuildGoal( const GoalData& goalData )
{
	return new StaticGardenGoalLogic(goalData.seedPos, goalData.occupiedPositions, goalData.type);
}

std::vector<IGardenGoalLogic*> LevelBuilder::BuildGoals( std::vector<GoalData> goalsData )
{
	std::vector<IGardenGoalLogic*> goals;
	for ( const auto& goalData : goalsData)
	{
		goals.emplace_back( BuildGoal(goalData) );
	}
	return goals;
}

