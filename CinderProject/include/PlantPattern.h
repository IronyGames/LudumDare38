#pragma once

#include "Typedef.h"

#include <set>
#include <vector>

struct PlantPattern
{
	struct Pattern
	{
		Year year = 0;
		std::vector<CoordsInt> relativePositions;

		bool operator<( const Pattern& other ) const
		{
			return year < other.year;
		}
	};

	std::set<Pattern> treePatterns;
	Year lifeRange;
};