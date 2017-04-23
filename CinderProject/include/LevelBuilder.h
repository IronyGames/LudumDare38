#pragma once

#include "Level.h"
#include <vector>

class ImageFlyweight;

class LevelBuilder
{
public:
	std::vector<Level> LoadLevels( std::string path, ImageFlyweight *imgs );
};