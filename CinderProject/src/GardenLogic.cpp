#include "GardenLogic.h"
#include "PlantLogic.h"

GardenRules::GardenRules(Segment<Year> _timeline, unsigned _gardenWidth, unsigned _gardenHeight)
: timeline(_timeline)
, gardenWidth(_gardenWidth)
, gardenHeight(_gardenHeight)
{

}

GardenLogic::GardenLogic(GardenRules rules_, std::vector<IGardenEntityLogic*> _plants)
	: rules( rules_ )
	, plants(_plants)
{}

GardenLogic::Dimensions GardenLogic::getDimensions() const
{
	return Dimensions(rules.gardenWidth, rules.gardenHeight);
}

Segment<Year> GardenLogic::getCurrentTimeState() const
{
	return rules.timeline;
}

void GardenLogic::updateGardenDelta( Year year )
{
	rules.timeline += year;
	for ( IGardenEntityLogic* gardenEntity : plants )
	{
		PlantLogic::CalculateStateResult result = gardenEntity->calculateStateTo(year);

		// TODO: Do stuff later
	}
}

std::vector<IGardenEntityLogic*> GardenLogic::getEntities() const
{
	return plants;
}

GardenLogic::Dimensions::Dimensions( unsigned witdh_, unsigned height_ ) : witdh( witdh_ )
, height( height_ )
{

}
