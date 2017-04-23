#pragma once

#include "Typedef.h"
#include "Segment.h"

#include <unordered_map>

class IGardenEntityLogic;

class GardenLogic
{
public:
	GardenLogic( Segment<Year> timeline_, unsigned gardenWidth_, unsigned gardenHeight_, std::vector<IGardenEntityLogic*> entities_ );

	struct Dimensions
	{
		Dimensions( unsigned witdh_, unsigned height_ );

		unsigned width = 0;
		unsigned height = 0;
	};
	Dimensions		getDimensions() const;
	Segment<Year>	getCurrentTimeState() const;

	std::vector<IGardenEntityLogic*> getEntities() const;

	void updateGardenDelta( Year year );

private:
	const Dimensions	dimensions;
	Segment<Year>		timeline;
	

	std::unordered_map<CoordsInt, IGardenEntityLogic*> world;

	std::vector<IGardenEntityLogic*> entities;
};