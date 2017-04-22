#include "PlantVisual.h"
#include "PlantLogic.h"
#include "IGardenEntityState.h"

PlantVisual::PlantVisual(PlantLogic* _logic)
:logic(_logic)
, m_growthColor(cinderColor(0.286, 0.475, 0.161))
, m_seedColor(cinderColor(0.42, 0.659, 0.263))
{

}

CoordsInt PlantVisual::getSeed() const {
	return logic->getInitialPosition();
}

std::vector<CoordsInt> PlantVisual::getGrownTiles() const {
	return logic->getCurrentState()->occupiedPositions();
}

cinderColor PlantVisual::getPlantTile(CoordsInt tile)
{
	return m_growthColor;
}

cinderColor PlantVisual::getSeedTile()
{
	return m_seedColor;
}
