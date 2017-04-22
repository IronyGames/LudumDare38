#pragma once

#include "Typedef.h"

#include <vector>

class IGardenEntityState
{
public:
	virtual ~IGardenEntityState() = default;

	virtual std::vector<CoordsInt> occupiedPositions() const = 0;
};