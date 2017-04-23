#pragma once

#include "Typedef.h"
#include "Segment.h"

class PlantVisual;
class GardenLogic;
class ImageFlyweight;

class GardenVisual {
public:
	GardenVisual(const GardenLogic *_logic, ImageFlyweight *_images);
	DimensionsInt getGardenSize() const;
	std::vector<PlantVisual*> getPlants() const;
	Image getSoilTile(CoordsInt position) const;
	Segment<Year> getTimeline();
	cinderColor getTimelineColor() const;
private:
	const GardenLogic *m_logic;
	cinderColor m_soilColor;
	cinderColor m_timelineColor;
	std::vector<std::vector<Image>> soilTextures;
	Image soilImage;
	int tileTextureSize;
};