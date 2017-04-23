#include "LevelBuilder.h"
#include "LevelLoader.h"
#include "GardenInitializationData.h"
#include "PlantLogic.h"
#include "GardenLogic.h"

std::vector<Level> LevelBuilder::LoadLevels( std::string path )
{
	std::vector<Level> levels;

	LevelLoader levelLoader;
	std::vector<LevelData> levelsData = levelLoader.LoadLevelData( path );

	for(const auto& levelData : levelsData)
	{
		const GardenInitializationData& gardenInitializationData = levelData.gardenInitializationData;

		std::vector<IGardenEntityLogic*> gardenObjects;
		for(const auto& kv : gardenInitializationData.initialEntities)
		{
			CoordsInt coord = kv.first;
			GardenInitializationData::Entity plant = kv.second;

			auto it = levelData.plantTypes.find( plant.name );
			const PlantData& plantData = it->second;
			gardenObjects.emplace_back( new PlantLogic( plantData.pattern, plant.seedYear, plant.age, coord) );
		}
		
		GardenLogic* gardenLogic = new GardenLogic( gardenInitializationData.timeline, gardenInitializationData.gardenWidth, gardenInitializationData.gardenHeight, std::move(gardenObjects) );
		levels.emplace_back( Level( gardenLogic ) );
	}

	return levels;
}
