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
	void render(PlantVisual *plant, Year year );
	void renderTile(cinderColor tileColor, int tileSize);
	void renderGardenTimeline(GardenVisual *garden);
	void renderGarden(GardenVisual *garden);
	void render(std::vector<PlantVisual*> plants, Year year );
	int tileSize;
	int tileSeparator;
	int timeLineHeight;
	int timeLineMargin;
	int markerHeight;
	void renderTimeline(cinderColor color, int startingX, int endingX, int markerX, int markerWidth);
	void renderPlantTimelines(std::vector<PlantVisual*> plants, double timepixelRelation, double currentYear);
public:
	Viewer();
	void render(std::vector<Animation2D*> *_text);
	void renderToWholeScreen(Image _image);
	DimensionsInt getWindowSize();
	int getFramesPerSecond();
	void begin();
	void end();
	void render(GardenVisual *garden);
	CoordsInt getGardenRenderingOffset(GardenVisual *garden);
	void renderPlant(PlantVisual *plant, int translation, int tileSize, double year);
};
