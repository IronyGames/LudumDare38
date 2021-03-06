#include "GardenVisual.h"
#include "GardenLogic.h"
#include "IGardenEntityLogic.h"
#include "IGardenEntityState.h"
#include "PlantVisual.h"
#include "ImageFlyweight.h"

GardenVisual::GardenVisual(const GardenLogic *_logic, ImageFlyweight *_images) :m_logic(_logic)
, m_soilColor(cinderColor(0.541, 0.302, 0.184))
, m_timelineColor(cinderColor(0.9,0.9,0.9))
, tileSize(30)
, tileSeparator(0)
, soilTexture(_images->get("../resources/soil.png"))
{
	
}

DimensionsInt GardenVisual::getGardenSize() const
{
	GardenLogic::Dimensions d = m_logic->getDimensions();
	return DimensionsInt(d.witdh, d.height);
}

std::vector<PlantVisual*> GardenVisual::getPlants() const
{
	std::vector<PlantVisual*> out;
	for (auto plant : m_logic->getEntities()){
		out.push_back(new PlantVisual((PlantLogic*)plant));
	}
	return out;
}

Image GardenVisual::getSoilTile(CoordsInt position) const
{
	return soilTexture;
}

Segment<Year> GardenVisual::getTimeline()
{
	return m_logic->getCurrentTimeState();
}

cinderColor GardenVisual::getTimelineColor() const {
	return m_timelineColor;
}

int GardenVisual::getTileSize() const {
	return tileSize;
}
int GardenVisual::getTileSeparator() const {
	return tileSeparator;
}

DimensionsInt GardenVisual::getGardenPixelSize()
{
	return getGardenSize() * getTileTranslation() - tileSeparator;
}

int GardenVisual::getTileTranslation()
{
	return tileSize + tileSeparator;
}