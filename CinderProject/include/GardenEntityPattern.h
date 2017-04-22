#pragma once

#include "Typedef.h"

#include <set>
#include <vector>
#include "Segment.h"

struct GardenEntityPattern
{
	struct Pattern
	{
		Pattern() = default;
		Pattern( Year year_ )
			: year(year_)
		{}

		Year year = 0;
		std::vector<CoordsInt> relativePositions;

		bool operator<( const Pattern& other ) const
		{
			return year < other.year;
		}
	};

	std::set<Pattern>	treePatterns;
	Segment<Year>		lifeRange;
};