#include "PlantVisual.h"
#include "PlantLogic.h"
#include "IGardenEntityState.h"

PlantVisual::PlantVisual(PlantLogic* _logic)
:m_logic(_logic)
, m_growthColor(cinderColor(0.286, 0.475, 0.161))
, m_seedColor(cinderColor(0.42, 0.659, 0.263))
, m_timelineColor(cinderColor(0.631, 0.847, 0.565))
{

}

CoordsInt PlantVisual::getSeed() const {
	return m_logic->getPosition();
}

std::vector<CoordsInt> PlantVisual::getGrownTiles() const {
	return m_logic->getOccupiedPositions();
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
	return m_logic->getTimeLine().getMin();
}

cinderColor PlantVisual::getTimelineColor()
{
	return m_timelineColor;
}

double PlantVisual::getMaxAge()
{
	return m_logic->getTimeLine().getMax();
}

double PlantVisual::getAge(Year year_) const
{
	return m_logic->getAge(year_);
}