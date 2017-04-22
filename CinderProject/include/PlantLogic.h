#pragma once

#include "Typedef.h"
#include "IGardenEntityLogic.h"
#include "PlantPattern.h"


enum class EPlantType
{
	k_tree,
};

class PlantLogic : public IGardenEntityLogic
{
public:
	PlantLogic( EPlantType type, PlantPattern pattern, CoordsInt intialPos, Year seedYear );
	~PlantLogic() override;

	const IGardenEntityState* getCurrentState() const override;
	void setCurrentState( owner<IGardenEntityState> state_ ) override;

	CoordsInt getInitialPosition() const override;
	Year getSeedYear() const override;

	CalculateStateResult calculateStateTo( Year year_ ) const override;

private:	
	const EPlantType	type;
	const PlantPattern	pattern;

	CoordsInt	initialPosition;
	Year		seedYear;

	owner<IGardenEntityState>		state;
};
