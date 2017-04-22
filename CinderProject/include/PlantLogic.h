#pragma once

#include "Typedef.h"
#include "IGardenEntityLogic.h"

#include <set>

enum class EPlantType
{
	k_tree,
};

struct PlantPattern
{
	struct Pattern
	{
		Year year = 0;
		std::vector<CoordsInt> relativePositions;

		bool operator<( const Pattern& other ) const
		{
			return year < other.year;
		}
	};

	std::set<Pattern> treePatterns;
	Year lifeRange;
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
