#pragma once

#include "Typedef.h"
#include "Segment.h"

class PlantVisual;
class GardenTileVisual;

class GardenVisual {
public:
	GardenVisual(DimensionsInt _size, std::vector<PlantVisual*> _plants);
	DimensionsInt getGardenSize() const;
	std::vector<PlantVisual*> getPlants() const;
	void setPlants(std::vector<PlantVisual*> _plants);
	cinderColor getSoilTile(CoordsInt position) const;
private:
	GardenTileVisual *m_soilTile;
	cinderColor m_soilColor;
	DimensionsInt m_size;
	std::vector<PlantVisual*> m_plants;
	int m_tileSeparation;
	int m_tileSize;
};