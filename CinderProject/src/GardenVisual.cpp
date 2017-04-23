#include "GardenVisual.h"
#include "GardenLogic.h"
#include "IGardenEntityLogic.h"
#include "IGardenEntityState.h"
#include "PlantVisual.h"
#include "ImageFlyweight.h"
#include <stdlib.h>

GardenVisual::GardenVisual(const GardenLogic *_logic, ImageFlyweight *_images) 
: m_logic(_logic)
, m_soilColor(cinderColor(0.541, 0.302, 0.184))
, soilImage(_images->get("../resources/soil.png"))
, m_timelineColor(cinderColor(0.9, 0.9, 0.9))
, tileTextureSize(16)
{
	DimensionsInt selectablePoints(soilImage->getWidth() - tileTextureSize, soilImage->getHeight() - tileTextureSize);
	GardenLogic::Dimensions d = m_logic->getDimensions();
	for (int c = 0; c < d.width; c++){
		std::vector<Image> v;
		for (int r = 0; r < d.height; r++){
			cinder::Area subArea(rand() % selectablePoints.x, rand() % selectablePoints.y, tileTextureSize, tileTextureSize);
			v.push_back(soilImage);
		}
		soilTextures.push_back(v);
	}
}

DimensionsInt GardenVisual::getGardenSize() const
{
	GardenLogic::Dimensions d = m_logic->getDimensions();
	return DimensionsInt(d.width, d.height);
}

std::vector<PlantVisual*> GardenVisual::getPlants() const
{
	std::vector<PlantVisual*> out;
	for (auto plant : m_logic->getEntities()){
		out.push_back(new PlantVisual((PlantLogic*)plant));
	}
	return out;
}

Image GardenVisual::getSoilTile( CoordsInt position ) const
{
	return soilTextures.at(position.x).at(position.y);
}

Segment<Year> GardenVisual::getTimeline()
{
	return m_logic->getCurrentTimeState();
}

cinderColor GardenVisual::getTimelineColor() const {
	return m_timelineColor;
}