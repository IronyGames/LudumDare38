#include "PlantVisual.h"
#include "PlantLogic.h"
#include "IGardenEntityState.h"

PlantVisual::PlantVisual(PlantLogic* _logic)
:m_logic(_logic)
, m_growthColor(cinderColor(0.286, 0.475, 0.161))
, m_seedColor(cinderColor(0.42, 0.659, 0.263))
{

}

CoordsInt PlantVisual::getSeed() const {
	return m_logic->getInitialPosition();
}

std::vector<CoordsInt> PlantVisual::getGrownTiles() const {
	return m_logic->getCurrentState()->occupiedPositions();
}

cinderColor PlantVisual::getPlantTile(CoordsInt tile)
{
	return m_growthColor;
}

cinderColor PlantVisual::getSeedTile()
{
	return m_seedColor;
}

double PlantVisual::getSeedYear()
{
	return m_logic->getSeedYear();
}
