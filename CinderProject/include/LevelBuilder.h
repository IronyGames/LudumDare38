#pragma once

#include "Level.h"
#include <vector>

class LevelBuilder
{
public:
	std::vector<Level> LoadLevels( std::string path );
};