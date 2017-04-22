#pragma once

#include "Typedef.h"

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

	virtual CoordsInt getInitialPosition() const = 0;
	virtual Year getSeedYear() const = 0;



	virtual const IGardenEntityState* getCurrentState() const = 0;
	virtual void setCurrentState( owner<IGardenEntityState> state ) = 0;
};