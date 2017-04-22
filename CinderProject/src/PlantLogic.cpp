#include "PlantLogic.h"
#include "IGardenEntityState.h"

struct PlantLogicState : public IGardenEntityState
{
	std::vector<CoordsInt> occupiedPositions() const override
	{
		return m_occupiedPositions;
	}
	
	std::vector<CoordsInt> m_occupiedPositions;
};

PlantLogic::PlantLogic( EPlantType type_, PlantPattern pattern_, CoordsInt initialPos_, Year seedYear_ )
	: type(type_)
	, pattern(pattern_)
	, initialPosition(initialPos_)
	, seedYear(seedYear_)
	, state( new PlantLogicState )
{}

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
	state = state_;
}

CoordsInt PlantLogic::getInitialPosition() const
{
	return initialPosition;
}

Year PlantLogic::getSeedYear() const
{
	return seedYear;
}

PlantLogic::CalculateStateResult PlantLogic::calculateStateTo( Year year_ ) const
{
	CalculateStateResult result;



	return result;
}
