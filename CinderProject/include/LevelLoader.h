#pragma once
#include "GardenEntityPattern.h"
#include "GardenInitializationData.h"
#include "GameFileLoader.h"

#include <map>
#include <string>
#include <vector>
#include "boost/optional/optional.hpp"


class GoalData
{
public:
	boost::optional<CoordsInt>	seedPos;
	std::vector<CoordsInt>		occupiedPositions;
	std::string					type;
};

class PlantData
{
public:
	GardenEntityPattern	pattern;
};

class LevelData
{
public:
	GardenInitializationData			gardenInitializationData;
	std::map<std::string, PlantData>	plantTypes;
	std::vector<GoalData>				goals;
};

class LevelLoader : public GameFileLoader
{
public:
	std::vector<LevelData> LoadLevelData( std::string path );

private:
	static CoordsInt getCoordFrom( const CinderJson& json );
	static std::vector<CoordsInt> getListCoordFrom( const CinderJson& json );
};