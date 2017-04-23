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
private:
	std::vector<std::vector<Image>> soilTextures;
	Image soilImage;
	const GardenLogic *logic;
	cinderColor m_soilColor;
	int tileTextureSize;
};