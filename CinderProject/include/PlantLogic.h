#pragma once

#include "Typedef.h"
#include "GardenEntityPattern.h"
#include "IGardenEntityLogic.h"

class PlantLogicState;

class PlantLogic : public IGardenEntityLogic
{
public:
	PlantLogic( GardenEntityPattern pattern, Year seedTime, Year age, CoordsInt pos, std::string type );
	~PlantLogic() override;

	std::vector<CoordsInt> getOccupiedPositions() const override;
	void setCurrentState( Year age, std::vector<CoordsInt> occupiedPositions ) override;

	CoordsInt getPosition() const override;
	Segment<Year> getTimeLine() const override;
	Year getSeedYear() const override;
	Year getAge( Year currentYear ) const override;
	std::string		getType() const override;

	CalculateStateResult calculateStateTo( Year year, Year deltaYear ) const override;

private:	
	const GardenEntityPattern	gardenEntityPattern;
	const std::string type;

	owner<PlantLogicState>	state;
};
