#pragma once

#include "Typedef.h"
#include "GardenEntityPattern.h"
#include "IGardenEntityLogic.h"
#include "EntityDef.h"

class PlantLogicState;


class PlantLogic : public IGardenEntityLogic
{
public:
	PlantLogic( EntityDef plantDef, Year seedTime, Year age, CoordsInt pos );
	~PlantLogic() override;

	std::vector<CoordsInt> getOccupiedPositions() const override;
	void setCurrentState( Year age, std::vector<CoordsInt> occupiedPositions ) override;

	CoordsInt getPosition() const override;
	Segment<Year> getTimeLine() const override;
	Year getSeedYear() const override;
	Year getAge( Year currentYear ) const override;
	std::string		getType() const override;
	bool			isStatic() const override;
	EntityDef		getEntityDef() const override;

	CalculateStateResult calculateStateTo( Year year, Year deltaYear ) const override;

private:	
	const EntityDef plantDef;
	owner<PlantLogicState>	state;
};
