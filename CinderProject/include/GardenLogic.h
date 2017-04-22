#pragma once

#include "Typedef.h"
#include "Segment.h"

class IGardenEntityLogic;

struct GardenRules
{
	GardenRules(Segment<Year> _timeline, unsigned _gardenWidth, unsigned _gardenHeight);
	Segment<Year> timeline;

	unsigned gardenWidth = 0;
	unsigned gardenHeight = 0;
};

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