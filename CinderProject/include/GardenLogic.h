#pragma once

#include "Typedef.h"
#include "Segment.h"

#include <unordered_map>
#include "EntityDef.h"

class IGardenEntityLogic;
class IGardenGoalLogic;

class GardenLogic
{
public:
	GardenLogic( Segment<Year> timeline_, unsigned gardenWidth_, unsigned gardenHeight_, std::vector<IGardenEntityLogic*> entities_, std::vector<IGardenGoalLogic*> objective_ );

	void plant( EntityDef entityDef, CoordsInt tile );
	EntityDef unPlant(CoordsInt tile);

	struct Dimensions
	{
		Dimensions( unsigned witdh_, unsigned height_ );

		unsigned witdh = 0;
		unsigned height = 0;
	};
	Dimensions		getDimensions() const;
	Segment<Year>	getCurrentTimeState() const;

	std::vector<IGardenEntityLogic*> getEntities() const;
	const IGardenEntityLogic* getEntityAt(CoordsInt coord) const;
	bool hasEntityAt( CoordsInt coord ) const;

	void updateGardenDelta( Year deltaYear );

	struct EvaluateGoalResult
	{
		bool haveWon = false;
	};
	EvaluateGoalResult evaluateGoal() const;

private:
	const Dimensions	dimensions;
	Segment<Year>		timeline;

	void refreshWorld();
	void addEntityToMap(IGardenEntityLogic* entity_);
	IGardenEntityLogic* getEntity(CoordsInt origin);
	

	std::unordered_map<CoordsInt, IGardenEntityLogic*> world;

	std::vector<IGardenEntityLogic*>	entities;
	std::vector<IGardenGoalLogic*>		objectives;
	
};