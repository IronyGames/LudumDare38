#pragma once

#include "Typedef.h"
#include "Segment.h"

#include <unordered_map>

class IGardenEntityLogic;

class GardenLogic
{
public:
	GardenLogic( Segment<Year> timeline_, unsigned gardenWidth_, unsigned gardenHeight_, std::vector<IGardenEntityLogic*> entities_ );

	void addEntity(IGardenEntityLogic* entity_);
	void unPlant(CoordsInt tile);

	struct Dimensions
	{
		Dimensions( unsigned witdh_, unsigned height_ );

		unsigned witdh = 0;
		unsigned height = 0;
	};
	Dimensions		getDimensions() const;
	Segment<Year>	getCurrentTimeState() const;

	std::vector<IGardenEntityLogic*> getEntities() const;

	void updateGardenDelta( Year deltaYear );

private:
	const Dimensions	dimensions;
	Segment<Year>		timeline;

	void addEntityToMap(IGardenEntityLogic* entity_);
	IGardenEntityLogic* getEntity(CoordsInt origin);
	std::unordered_map<CoordsInt, IGardenEntityLogic*> world;

	std::vector<IGardenEntityLogic*> entities;
};