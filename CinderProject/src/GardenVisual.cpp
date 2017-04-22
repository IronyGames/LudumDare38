#include "GardenVisual.h"

GardenVisual::GardenVisual(DimensionsInt _size, std::vector<PlantVisual*> _plants)
: m_size(_size)
, m_plants(_plants)
, m_soilColor(cinderColor(0.541, 0.302, 0.184))
{
}

DimensionsInt GardenVisual::getGardenSize() const
{
	return m_size;
}

std::vector<PlantVisual*> GardenVisual::getPlants() const
{
	return m_plants;
}

void GardenVisual::setPlants(std::vector<PlantVisual*> _plants)
{
	m_plants = _plants;
}

cinderColor GardenVisual::getSoilTile(CoordsInt position) const
{
	return m_soilColor;
}


