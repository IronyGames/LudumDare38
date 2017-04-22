#pragma once

#include "Typedef.h"
#include "Segment.h"

class IGardenEntityLogic;

struct GardenRules
{
	Segment<Year> timeline;

	unsigned gardenWidth = 0;
	unsigned gardenHeight = 0;
};

class GardenLogic
{
public:
	GardenLogic( GardenRules rules_ );

	struct Dimensions
	{
		Dimensions( unsigned witdh_, unsigned height_ );

		unsigned witdh = 0;
		unsigned height = 0;
	};
	Dimensions		getDimensions() const;
	Segment<Year>	getCurrentTimeState() const;

	void updateGardenTo( Year year );

private:
	GardenRules		rules;
	Segment<Year>	currentState;

	std::map<CoordsInt, IGardenEntityLogic*> world;

	std::vector<owner<IGardenEntityLogic>> plants;
};