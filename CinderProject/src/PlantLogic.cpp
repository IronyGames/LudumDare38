#include "PlantLogic.h"
#include "IGardenEntityState.h"
#include "GardenEntityPattern.h"

#include <unordered_set>

class PlantLogicState : public IGardenEntityState
{
public:
	std::vector<CoordsInt> getOccupiedPositions() const override
	{
		return occupiedPositions;
	}

	Year currentAge() const override
	{
		return age;
	}

	CoordsInt getPosition() const
	{
		return seedPosition;
	}
	
	std::vector<CoordsInt> occupiedPositions;
	Year age;
	CoordsInt seedPosition;
};

PlantLogic::PlantLogic( GardenEntityPattern pattern_, Year age_, CoordsInt pos_ )
	: pattern(pattern_)
	, state( new PlantLogicState )
{
	state->age = age_;
	state->seedPosition = pos_;
}

PlantLogic::~PlantLogic()
{
	delete state;
}

const IGardenEntityState* PlantLogic::getCurrentState() const
{
	return state;
}

void PlantLogic::setCurrentState( owner<IGardenEntityState> state_ )
{
	delete state;
	//state = state_;
}

CoordsInt PlantLogic::getPosition() const
{
	return state->getPosition();
}

Segment<Year> PlantLogic::getCurrentLife() const
{
	return pattern.lifeRange;
}

Year PlantLogic::getAge() const
{
	return state->currentAge();
}

PlantLogic::CalculateStateResult PlantLogic::calculateStateTo( Year deltaYear ) const
{
	CalculateStateResult result;

	Segment<Year> currentYear = getCurrentLife();
	currentYear += deltaYear;
	auto it = pattern.treePatterns.lower_bound( currentYear.get() );
	if (it != pattern.treePatterns.end() )
	{
		CoordsInt initialPos = getPosition();
		std::vector<CoordsInt> o = getCurrentState()->getOccupiedPositions();
		std::unordered_set<CoordsInt> occupiedPositions( o.begin(), o.end() );

		for ( CoordsInt relativePos : it->relativePositions)
		{
			occupiedPositions.emplace(relativePos + initialPos);
		}
		result.occupiedPositions.insert( result.occupiedPositions.end(), occupiedPositions.begin(), occupiedPositions.end() );
	}

	return result;
}
