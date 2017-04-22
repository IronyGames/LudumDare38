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
private:
	const GardenLogic *logic;
	cinderColor m_soilColor;
};