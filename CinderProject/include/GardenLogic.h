#pragma once

#include "Typedef.h"
#include "Segment.h"
#include "GardenRules.h"

class IGardenEntityLogic;

class GardenLogic
{
public:
	GardenLogic(GardenRules rules_, std::vector<IGardenEntityLogic*> _plants);

	struct Dimensions
	{
		Dimensions( unsigned witdh_, unsigned height_ );

		unsigned witdh = 0;
		unsigned height = 0;
	};
	Dimensions		getDimensions() const;
	Segment<Year>	getCurrentTimeState() const;

	std::vector<IGardenEntityLogic*> getEntities() const;

	void updateGardenTo( Year year );

private:
	GardenRules		rules;
	Segment<Year>	currentState;

	std::map<CoordsInt, IGardenEntityLogic*> world;

	std::vector<owner<IGardenEntityLogic>> plants;
};