#include "PlantLogic.h"
#include "IGardenEntityState.h"
#include "GardenEntityPattern.h"

#include <unordered_set>

class PlantLogicState : public IGardenEntityState
{
public:
	PlantLogicState( Year seedYear_ )
		: seedYear(seedYear_)
	{}

	std::vector<CoordsInt> getOccupiedPositions() const override
	{
		return occupiedPositions;
	}

	Year getAge( Year currentYear ) const override
	{
		if(currentYear < getSeedYear() )
		{
			return 0;
		}
		return currentYear - getSeedYear();
	}
	
	Year getSeedYear() const override
	{
		return seedYear;
	}

	CoordsInt getPosition() const
	{
		return seedPosition;
	}

	const Year seedYear;

	std::vector<CoordsInt> occupiedPositions;
	Segment<Year> plantTimeline;
	
	CoordsInt seedPosition;
};

PlantLogic::PlantLogic( GardenEntityPattern pattern_, Year seedTime, Year age_, CoordsInt pos_, std::string type_ )
	: gardenEntityPattern(pattern_)
	, state( new PlantLogicState( seedTime ) )
	, type(type_)
{
	state->plantTimeline = Segment<Year>(gardenEntityPattern.lifeRange.getMin(), gardenEntityPattern.lifeRange.getMax(), age_);
	state->seedPosition = pos_;
}

PlantLogic::~PlantLogic()
{
	delete state;
}

std::vector<CoordsInt> PlantLogic::getOccupiedPositions() const
{
	return state->getOccupiedPositions();
}

void PlantLogic::setCurrentState( Year age, std::vector<CoordsInt> occupiedPositions )
{
	state->plantTimeline = age;
	state->occupiedPositions = occupiedPositions;
}

CoordsInt PlantLogic::getPosition() const
{
	return state->getPosition();
}

Segment<Year> PlantLogic::getTimeLine() const
{
	return state->plantTimeline;
}

Year PlantLogic::getSeedYear() const
{
	return state->getSeedYear();
}

Year PlantLogic::getAge( Year currentYear ) const
{
	return state->getAge( currentYear );
}

std::string PlantLogic::getType() const
{
	return type;
}

PlantLogic::CalculateStateResult PlantLogic::calculateStateTo( Year year, Year deltaYear ) const
{
	const Segment<Year> validTime( getSeedYear() + getTimeLine().getMin(), getSeedYear() + getTimeLine().getMax(), year );
	Year age = getAge( year ) + deltaYear;

	if (year < validTime.getMin() || age <= 0)
	{
		return CalculateStateResult();
	}

	CalculateStateResult result;

	result.age = age;
	
	const auto& node = gardenEntityPattern.getFirstNodeInSegmentFrom( age );

	CoordsInt initialPos = getPosition();
	std::vector<CoordsInt> o = getOccupiedPositions();
	std::unordered_set<CoordsInt> occupiedPositions;//( o.begin(), o.end() );

	for ( CoordsInt relativePos : node.relativePositions)
	{
		occupiedPositions.emplace(relativePos + initialPos);
	}
	result.occupiedPositions.insert( result.occupiedPositions.end(), occupiedPositions.begin(), occupiedPositions.end() );


	return result;
}
