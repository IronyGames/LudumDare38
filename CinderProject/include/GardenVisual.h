#pragma once

#include "Typedef.h"
#include "Segment.h"

class PlantVisual;
class GardenLogic;

class GardenVisual {
public:
	GardenVisual(const GardenLogic *_logic);
	DimensionsInt getGardenSize() const;
	std::vector<PlantVisual*> getPlants() const;
	cinderColor getSoilTile(CoordsInt position) const;
	Segment<Year> getTimeline();
	cinderColor getTimelineColor() const;
private:
	const GardenLogic *m_logic;
	cinderColor m_soilColor;
	cinderColor m_timelineColor;
};