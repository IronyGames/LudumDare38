
#pragma once
#include "IGardenGoalLogic.h"

class StaticGardenGoalLogic : public IGardenGoalLogic
{
public:
	StaticGardenGoalLogic( boost::optional<CoordsInt> seedPosition_, std::vector<CoordsInt> occupiedPositions_, std::string entityType_  );

	boost::optional<CoordsInt> getSeedPosition() const override;
	std::vector<CoordsInt> getOccupiedPositions() const override;
	std::string getEntityType() const override;

private:
	boost::optional<CoordsInt> seedPosition;
	std::vector<CoordsInt> occupiedPositions;
	std::string entityType;
};