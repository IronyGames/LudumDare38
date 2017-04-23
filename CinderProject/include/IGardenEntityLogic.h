#pragma once

#include "Typedef.h"
#include "Segment.h"

class IGardenEntityState;

class IGardenEntityLogic
{
public:
	virtual ~IGardenEntityLogic() = default;

	struct CalculateStateResult
	{
		std::vector<CoordsInt> occupiedPositions;
	};
	virtual CalculateStateResult calculateStateTo( Year year ) const = 0;

	virtual CoordsInt getPosition() const = 0;
	virtual Segment<Year> getCurrentLife() const = 0;
	virtual Year getAge() const = 0;


	virtual const IGardenEntityState* getCurrentState() const = 0;
	virtual void setCurrentState( owner<IGardenEntityState> state ) = 0;
};