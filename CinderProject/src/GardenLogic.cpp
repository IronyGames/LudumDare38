#include "GardenLogic.h"
#include "PlantLogic.h"

GardenLogic::GardenLogic( GardenRules rules_ )
	: rules( rules_ )
	, currentState( rules_.timeline )
{}

GardenLogic::Dimensions GardenLogic::getDimensions() const
{
	return Dimensions(rules.gardenWidth, rules.gardenHeight);
}

Segment<Year> GardenLogic::getCurrentTimeState() const
{
	return currentState;
}

void GardenLogic::updateGardenTo( Year year )
{
	for ( IGardenEntityLogic* gardenEntity : plants )
	{
		PlantLogic::CalculateStateResult result = gardenEntity->calculateStateTo(year);

		// Do stuff later
	}
}

GardenLogic::Dimensions::Dimensions( unsigned witdh_, unsigned height_ ) : witdh( witdh_ )
, height( height_ )
{

}
