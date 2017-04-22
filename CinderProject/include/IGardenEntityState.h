#pragma once

#include "Typedef.h"

#include <vector>

class IGardenEntityState
{
public:
	virtual ~IGardenEntityState() = default;

	virtual std::vector<CoordsInt> getOccupiedPositions() const = 0;
	virtual Year currentAge() const = 0;
};