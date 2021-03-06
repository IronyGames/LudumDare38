#pragma once

#include "Typedef.h"

class PlantLogic;

class PlantVisual{
public:
	PlantVisual(PlantLogic* _logic);
	std::vector<CoordsInt> getGrownTiles() const;
	CoordsInt getSeed() const;
	cinderColor getPlantTile(CoordsInt tile);
	cinderColor getSeedTile();
	double getSeedYear();
	cinderColor getTimelineColor();
	double getMaxAge();
	double getAge( Year year_ ) const;

private:
	PlantLogic* m_logic;
	cinderColor m_growthColor;
	cinderColor m_seedColor;
	cinderColor m_timelineColor;
};
