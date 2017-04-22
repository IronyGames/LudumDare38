#pragma once

#include "Typedef.h"
#include "Segment.h"

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
	void renderGardenTimeline(GardenVisual *garden);
	void renderGarden(GardenVisual *garden);
	void render(std::vector<PlantVisual*> plants);
	int tileSize;
	int tileSeparator;
	int timeLineHeight;
	int timeLineMargin;
	CoordsInt getTileTranslation(CoordsInt tile);
	DimensionsInt getGardenSize(DimensionsInt size);
	void renderTimeline(cinderColor color, int startingX, int endingX, int markerX, int markerWidth);
	void renderPlantTimelines(std::vector<PlantVisual*> plants);
public:
	Viewer();
	void render(std::vector<Animation2D*> *_text);
	DimensionsInt getWindowSize();
	int getFramesPerSecond();
	void begin();
	void end();
	void render(GardenVisual *garden);
	
};
