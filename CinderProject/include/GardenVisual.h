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
	Segment<Year> getTimeline();
	cinderColor getTimelineColor() const;
	DimensionsInt getGardenPixelSize();
	int getTileTranslation();
	int getTileSize() const;
	int getTileSeparator() const;
	Image getSoilTile(CoordsInt position) const;
private:
	const GardenLogic *m_logic;
	cinderColor m_soilColor;
	cinderColor m_timelineColor;

	CoordsInt centeringOffset;
	int tileSize;
	int tileSeparator;
	Image soilTexture;
};