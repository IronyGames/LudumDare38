#pragma once

#include "Typedef.h"

#include <set>
#include <vector>
#include "Segment.h"

struct GardenEntityPattern
{
	struct PatternNode
	{
		PatternNode() = default;

		Year year = 0;
		std::vector<CoordsInt> relativePositions;

		bool operator<( const PatternNode& other ) const
		{
			return year < other.year;
		}
	};

	const PatternNode& getFirstNodeInSegmentFrom( Year age ) const
	{
		assert(age >= 0);
		assert(!treePatterns.empty());

		for( auto it = treePatterns.begin(); it != treePatterns.end(); ++it )
		{
			const PatternNode& pattern = *it;
			if ( age < pattern.year )
			{
				--it;
				return *it;
			}
		}


		return *treePatterns.rbegin();
	}

	std::set<PatternNode>	treePatterns;
	Segment<Year>		lifeRange;
};