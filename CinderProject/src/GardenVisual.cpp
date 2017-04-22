#include "GardenVisual.h"
#include "GardenLogic.h"
#include "IGardenEntityLogic.h"
#include "IGardenEntityState.h"
#include "PlantVisual.h"

GardenVisual::GardenVisual(const GardenLogic *_logic)
:logic(_logic)
, m_soilColor(cinderColor(0.541, 0.302, 0.184))
{
}

DimensionsInt GardenVisual::getGardenSize() const
{
	GardenLogic::Dimensions d = logic->getDimensions();
	return DimensionsInt(d.witdh, d.height);
}

std::vector<PlantVisual*> GardenVisual::getPlants() const
{
	std::vector<PlantVisual*> out;
	for (auto plant : logic->getEntities()){
		CoordsInt seed = plant->getInitialPosition();
		std::vector<CoordsInt> positions = plant->getCurrentState()->occupiedPositions();
		out.push_back(new PlantVisual(seed, positions));
	}
	return out;
}

cinderColor GardenVisual::getSoilTile(CoordsInt position) const
{
	return m_soilColor;
}


