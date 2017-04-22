#pragma once

#include "GardenRules.h"
#include "PlantPattern.h"
#include "GardenLogic.h"
#include "GardenVisual.h"

#include <vector>


class LevelData
{
public:
	GardenRules gardenRules;
	PlantPattern platPattern;
};

class LevelLoader
{
public:
	std::vector<LevelData> LoadLevels( std::string path )
	{
		LevelData levelData;

		levelData.gardenRules.gardenHeight = 13;
		levelData.gardenRules.gardenWidth = 13;
		levelData.gardenRules.timeline = Segment<Year>(1, 2000, 1);


		return { levelData };
	}
};

class Level
{
	GardenLogic gardenLogic;
	GardenVisual gardenVisual;
};


class LevelBuilder
{
public:
	std::vector<Level> LoadLevels( std::string path )
	{
		LevelLoader levelLoader;
		std::vector<LevelData> levelData = levelLoader.LoadLevels(path);

		return {};
	}
	
};