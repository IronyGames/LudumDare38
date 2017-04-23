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
		Year age = 0;
		std::vector<CoordsInt> occupiedPositions;
	};
	virtual CalculateStateResult calculateStateTo( Year year, Year deltaYear ) const = 0;

	virtual CoordsInt		getPosition() const = 0;
	virtual Segment<Year>	getTimeLine() const = 0;
	virtual Year			getSeedYear() const = 0;
	virtual Year			getAge( Year currentYear ) const = 0;
	virtual std::vector<CoordsInt> getOccupiedPositions() const = 0;

	virtual void setCurrentState( Year age, std::vector<CoordsInt> occupiedPositions ) = 0;
};