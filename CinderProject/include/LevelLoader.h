#pragma once
#include "GardenEntityPattern.h"
#include "GardenInitializationData.h"
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
	GardenInitializationData	gardenRules;
	std::map<std::string, PlantData> plantTypes;
};

class LevelLoader
{
public:
	std::vector<LevelData> LoadLevelData( std::string path );
};