#pragma once

#include "Typedef.h"
#include "GardenEntityPattern.h"
#include "IGardenEntityLogic.h"

class PlantLogicState;

class PlantLogic : public IGardenEntityLogic
{
public:
	PlantLogic( GardenEntityPattern pattern, Year age, CoordsInt pos );
	~PlantLogic() override;

	const IGardenEntityState* getCurrentState() const override;
	void setCurrentState( owner<IGardenEntityState> state_ ) override;

	CoordsInt getPosition() const override;
	Segment<Year> getCurrentLife() const override;
	Year getAge() const override;

	CalculateStateResult calculateStateTo( Year year_ ) const override;

private:	
	const GardenEntityPattern	pattern;

	owner<PlantLogicState>	state;
};
