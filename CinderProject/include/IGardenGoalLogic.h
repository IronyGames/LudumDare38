#pragma once

#include "Typedef.h"

#include "boost/optional/optional.hpp"
#include <vector>

class IGardenGoalLogic
{
public:
	virtual boost::optional<CoordsInt>	getSeedPosition() const = 0;
	virtual std::vector<CoordsInt>		getOccupiedPositions() const = 0;
	virtual std::string					getEntityType() const = 0;
};