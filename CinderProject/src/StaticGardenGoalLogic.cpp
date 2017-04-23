#include "StaticGardenGoalLogic.h"

StaticGardenGoalLogic::StaticGardenGoalLogic( boost::optional<CoordsInt> seedPosition_, std::vector<CoordsInt> occupiedPositions_, std::string entityType_ )
	: seedPosition(seedPosition_)
	, occupiedPositions(occupiedPositions_)
	, entityType(entityType_)
{}

boost::optional<CoordsInt> StaticGardenGoalLogic::getSeedPosition() const
{
	return seedPosition;
}

std::vector<CoordsInt> StaticGardenGoalLogic::getOccupiedPositions() const
{
	return occupiedPositions;
}

std::string StaticGardenGoalLogic::getEntityType() const
{
	return entityType;
}
