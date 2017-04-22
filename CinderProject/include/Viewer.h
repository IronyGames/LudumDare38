#pragma once

#include "Typedef.h"

class Animation2D;
class Spritesheet;
class GardenVisual;
class PlantVisual;
class GardenTileVisual;

class Viewer{
private:
	void renderAnimation2D(Animation2D *animation);
	void renderSpritesheet(Spritesheet *sheet);
	DimensionsInt windowSize;
	float zoom;
	int framesPerSecond;
	cinderColor* backgroundColor;
	void render(PlantVisual *plant);
	void renderTile(cinderColor tileColor);
	void render(std::vector<PlantVisual*> plants);
	int tileSize;
	int tileSeparator;
	CoordsInt getTileTranslation(CoordsInt tile);
	DimensionsInt getGardenSize(DimensionsInt size);
public:
	Viewer();
	void render(std::vector<Animation2D*> *_text);
	DimensionsInt getWindowSize();
	int getFramesPerSecond();
	void begin();
	void end();
	void render(GardenVisual *garden);
};
