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
	void renderPlant(PlantVisual *plant, int translation, int tileSize);
	void renderTile(cinderColor tileColor, int tileSize);
	void renderGardenTimeline(GardenVisual *garden);
	void renderGarden(GardenVisual *garden);
	int timeLineHeight;
	int timeLineMargin;
	int markerHeight;
	void renderTimeline(cinderColor color, int startingX, int endingX, int markerX, int markerWidth);
	void renderPlantTimelines(std::vector<PlantVisual*> plants, double timepixelRelation, double currentYear);
public:
	Viewer();
	void render(std::vector<Animation2D*> *_text);
	DimensionsInt getWindowSize();
	int getFramesPerSecond();
	void begin();
	void end();
	void render(GardenVisual *garden);
	CoordsInt getGardenRenderingOffset(GardenVisual *garden);
};
