#include "LevelLoader.h"
#include "GameFileLoader.h"

std::vector<LevelData> LevelLoader::LoadLevelData( std::string path )
{
	std::vector<LevelData> levelsData;

	CinderJson jsonLevels = getJsonData( path );
	
	for (const CinderJson& level : jsonLevels.getChild("levels"))
	{
		LevelData levelData;

		levelData.gardenInitializationData.gardenWidth = level.getValueForKey<int>( "width" );
		levelData.gardenInitializationData.gardenHeight = level.getValueForKey<int>( "height" );

		const Year maxTime = level.getValueForKey<int>( "max_time" );
		const Year currentTime = level.getValueForKey<int>( "current_time" );

		levelData.gardenInitializationData.timeline = Segment<Year>( 0, maxTime, currentTime );

		for ( const CinderJson& initialPlantsJson : level.getChild("initial_plants") )
		{
			GardenInitializationData::Entity plant;
			plant.name = initialPlantsJson.getValueForKey<std::string>( "plant_type" );
			plant.seedYear = initialPlantsJson.getValueForKey<int>( "seed_year" );

			CoordsInt coord = getCoordFrom( initialPlantsJson.getChild("coord") );
			levelData.gardenInitializationData.initialEntities[coord] = plant;
		}

		for(const CinderJson& plantJson : level.getChild( "plants" ))
		{
			PlantData plantData;
			std::string name = plantJson.getValueForKey<std::string>( "name" );

			for (const CinderJson& patternJson : plantJson.getChild("pattern") )
			{
				GardenEntityPattern::PatternNode pattern;
				pattern.year = patternJson.getValueForKey<int>( "year" );
				pattern.relativePositions = getListCoordFrom( patternJson.getChild( "coords" ) );

				plantData.pattern.treePatterns.emplace( pattern );
			}

			plantData.pattern.lifeRange = Segment<Year>( 0, plantJson.getValueForKey<int>("lifeRange"), 0 );

			levelData.plantTypes.emplace(name, plantData);
		}

		levelsData.emplace_back(levelData);
	}

	return levelsData;
}

CoordsInt LevelLoader::getCoordFrom( const CinderJson& json )
{
	CoordsInt coord;
	assert(json.getNumChildren() == 2);

	coord.x = json.getValueAtIndex<int>( 0 );
	coord.y = json.getValueAtIndex<int>( 1 );

	return coord;
}

std::vector<CoordsInt> LevelLoader::getListCoordFrom( const CinderJson& json )
{
	std::vector<CoordsInt> coords;
	for (auto it = json.begin(); it != json.end();)
	{
		const int x = it->getValue<int>();
		++it;
		const int y = it->getValue<int>();
		++it;
		
		coords.emplace_back(CoordsInt(x, y));
	}

	return coords;
}
