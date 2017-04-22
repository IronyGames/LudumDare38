#include "GardenLogic.h"
#include "PlantLogic.h"
#include "IGardenEntityLogic.h"
#include "IGardenEntityState.h"

#include <cassert>

GardenLogic::GardenLogic( Segment<Year> timeline_, unsigned gardenWidth_, unsigned gardenHeight_, std::vector<IGardenEntityLogic*> entities_ )
	: timeline( timeline_ )
	, dimensions( gardenWidth_, gardenHeight_ )
	, entities(std::move( entities_ ))
{
	for (IGardenEntityLogic* entity : entities )
	{
		for (CoordsInt coord : entity->getCurrentState()->getOccupiedPositions() )
		{
			assert( world.find(coord) == world.end() );
			world[coord] = entity;
		}
	}
}

GardenLogic::Dimensions GardenLogic::getDimensions() const
{
	return dimensions;
}

Segment<Year> GardenLogic::getCurrentTimeState() const
{
	return timeline;
}

void GardenLogic::updateGardenTo( Year year )
{
	for ( IGardenEntityLogic* gardenEntity : entities )
	{
		PlantLogic::CalculateStateResult result = gardenEntity->calculateStateTo(year);
		// Do stuff later
	}
}

std::vector<IGardenEntityLogic*> GardenLogic::getEntities() const
{
	return entities;
}

GardenLogic::Dimensions::Dimensions( unsigned witdh_, unsigned height_ ) : witdh( witdh_ )
, height( height_ )
{

}
