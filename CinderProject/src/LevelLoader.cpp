#include "LevelLoader.h"

std::vector<LevelData> LevelLoader::LoadLevelData( std::string path )
{
	LevelData levelData;

	levelData.gardenRules.gardenHeight = 13;
	levelData.gardenRules.gardenWidth = 13;
	levelData.gardenRules.timeline = Segment<Year>( 1, 2000, 499 );

	GardenInitializationData::Entity plant;
	plant.name = "plant_1";
	plant.seedYear = 500;
	levelData.gardenRules.initialEntities[CoordsInt( 3, 3 )] = plant;

	PlantData plantData;
	plantData.pattern.lifeRange = Segment<Year>( 0, 200, 0 );

	GardenEntityPattern::PatternNode pattern1;
	pattern1.year = 0;
	pattern1.relativePositions = {CoordsInt( 0,0 )};

	GardenEntityPattern::PatternNode pattern2;
	pattern2.year = 100;
	pattern2.relativePositions = {CoordsInt( 0,0 ), CoordsInt( 0,1 ), CoordsInt( 1,0 ), CoordsInt( 1,1 )};

	GardenEntityPattern::PatternNode pattern3;
	pattern3.year = 200;
	pattern3.relativePositions = {CoordsInt( 0,0 ), CoordsInt( 0,1 ), CoordsInt( 1,0 ), CoordsInt( 1,1 ), CoordsInt( 2,1 ), CoordsInt( 2,2 ), CoordsInt( 1,2 )};

	plantData.pattern.treePatterns = std::set<GardenEntityPattern::PatternNode>( {pattern1, pattern2, pattern3} );
	levelData.plantTypes["plant_1"] = plantData;

	return{levelData};
}
