#include "LevelLoader.h"

std::vector<LevelData> LevelLoader::LoadLevelData( std::string path )
{
	LevelData levelData;

	levelData.gardenRules.gardenHeight = 13;
	levelData.gardenRules.gardenWidth = 13;
	levelData.gardenRules.timeline = Segment<Year>( 1, 2000, 1 );

	GardenInitializationData::Entity plant;
	plant.name = "plant_1";
	plant.age = 0;
	levelData.gardenRules.initialEntities[CoordsInt( 5, 5 )] = plant;

	PlantData plantData;
	plantData.pattern.lifeRange = Segment<Year>( 1, 200, 0 );

	GardenEntityPattern::Pattern pattern1;
	pattern1.year = 0;
	pattern1.relativePositions = {CoordsInt( 0,0 )};

	GardenEntityPattern::Pattern pattern2;
	pattern2.year = 20;
	pattern2.relativePositions = {CoordsInt( 0,0 ), CoordsInt( 0,1 ), CoordsInt( 1,0 ), CoordsInt( 1,1 )};

	plantData.pattern.treePatterns = std::set<GardenEntityPattern::Pattern>( {pattern1, pattern2} );
	levelData.plantTypes["plant_1"] = plantData;

	return{levelData};
}
