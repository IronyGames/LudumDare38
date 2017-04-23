#pragma once
#include "GardenEntityPattern.h"
#include "GardenInitializationData.h"
#include "GameFileLoader.h"

#include <map>
#include <string>
#include <vector>


class PlantData
{
public:
	GardenEntityPattern	pattern;
};

class LevelData
{
public:
	GardenInitializationData	gardenInitializationData;
	std::map<std::string, PlantData> plantTypes;
};

class LevelLoader : public GameFileLoader
{
public:
	std::vector<LevelData> LoadLevelData( std::string path );

private:
	static CoordsInt getCoordFrom( const CinderJson& json );
	static std::vector<CoordsInt> getListCoordFrom( const CinderJson& json );
};