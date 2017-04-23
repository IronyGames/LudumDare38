#include "Viewer.h"
#include "Spritesheet.h"
#include "cinder\gl\wrapper.h"
#include "cinder\gl\draw.h"
#include "Animation2D.h"
#include "Typedef.h"
#include <vector>
#include "GardenVisual.h"
#include "PlantVisual.h"

Viewer::Viewer()
:windowSize(DimensionsInt(1280,720))
, zoom(1.0)
, framesPerSecond(60)
, backgroundColor(new cinderColor(0.216, 0.353, 0.486))
, timeLineHeight(5)
, timeLineMargin(10)
, markerHeight(15)
{

}

void Viewer::renderSpritesheet(Spritesheet *sheet)
{
	renderAnimation2D(sheet->getCurrentAnimation());
}

void Viewer::renderAnimation2D(Animation2D *animation)
{
	CoordsInt* offset = animation->getOffset();
	DimensionsInt* size = animation->getTileSize();
	int currentTile = animation->getCurrentTile();

	int columns = animation->tileColumns;

	Image image = animation->getImage();

	int w = offset->x;
	int h = offset->y;
	if (columns != 0){
		w += ((currentTile % columns) * size->x);
		h += ((currentTile / columns) * size->y);
	}

	cinder::Area sub(
		w, h,
		w + size->x, h + size->y
		);

	cinder::Rectf pos(
		0, 0,
		size->x, (size->y)
		);

	cinder::gl::draw(image, sub, pos);
}

void Viewer::render(std::vector<Animation2D*> *_text)
{
	cinder::gl::pushMatrices();
	if (_text->size() > 0){
		DimensionsInt tS(_text->at(0)->getTileSize()->x+1, 0);
		
		for (int i = 0; i < _text->size(); i++){
			Animation2D* a = _text->at(i);
			renderAnimation2D(a);
			cinder::gl::translate(tS);
		}
	}
	cinder::gl::popMatrices();
}

DimensionsInt Viewer::getWindowSize()
{
	return windowSize * (int)zoom;
}

int Viewer::getFramesPerSecond()
{
	return framesPerSecond;
}

void Viewer::begin()
{
	cinder::gl::pushMatrices();
	cinder::gl::clear(*backgroundColor);
	cinder::gl::scale(zoom, zoom);
}

void Viewer::end()
{
	cinder::gl::popMatrices();
}

void Viewer::render(GardenVisual *garden)
{
	DimensionsInt size = garden->getGardenSize();
	
	cinder::gl::pushMatrices();
	cinder::gl::translate(getGardenRenderingOffset(garden));
	renderGarden(garden);
	std::vector<PlantVisual*> plants = garden->getPlants();
	for (auto plant = plants.begin(); plant != plants.end(); plant++){
		renderPlant(*plant, garden->getTileTranslation(), garden->getTileSize(), garden->getTimeline().get());
	}
	cinder::gl::popMatrices();

	cinder::gl::pushMatrices();
	cinder::gl::translate(0, 2 * (windowSize).y / 3);
	renderGardenTimeline(garden);
	cinder::gl::popMatrices();
}

void Viewer::renderGarden(GardenVisual *garden)
{
	DimensionsInt size = garden->getGardenSize();
	int translation = garden->getTileSize() + garden->getTileSeparator();

	cinder::gl::pushMatrices();
	for (int r = 0; r < size.y; r++){
		cinder::gl::pushMatrices();
		for (int c = 0; c < size.x; c++){
			renderTile(garden->getSoilTile(CoordsInt(c, r)), garden->getTileSize());
			cinder::gl::translate(translation, 0, 0);
		}
		cinder::gl::popMatrices();
		cinder::gl::translate(0, translation, 0);
	}
	cinder::gl::popMatrices();
}

void Viewer::renderGardenTimeline(GardenVisual *garden)
{
	cinderColor color = garden->getTimelineColor();
	int startingX = timeLineMargin, size = windowSize.x - timeLineMargin - startingX;
	int markerWidth = timeLineHeight;

	Segment<double> timeline = garden->getTimeline();
	int maxT = timeline.getMax(), minT = timeline.getMin();
	double timepixelRelation = ((double)size) / ((double)maxT - (double)minT);
	double pixelPresent = timepixelRelation * timeline.get();

	renderTimeline(color, startingX, size, pixelPresent, markerWidth);

	cinder::gl::pushMatrices();
	cinder::gl::translate(startingX, markerHeight + timeLineMargin);
	renderPlantTimelines(garden->getPlants(), timepixelRelation, timeline.get());
	cinder::gl::popMatrices();
}

void Viewer::renderPlant(PlantVisual *plant, int translation, int tileSize, double year)
{
	CoordsInt seedPosition = plant->getSeed();
	std::vector<CoordsInt> grownTiles = plant->getGrownTiles();
	
	for (auto growth : grownTiles ){
		cinder::gl::pushMatrices();
		CoordsInt pixelTranslation = translation*(growth);
		cinder::gl::translate(pixelTranslation);
		renderTile(plant->getPlantTile(growth), tileSize);
		cinder::gl::popMatrices();
	}

	cinder::gl::pushMatrices();
	cinder::gl::translate( translation * ( seedPosition ) );
	const Year age = plant->getAge( year );
	if(age > 0)
	{
		renderTile( plant->getSeedTile(), tileSize );
	}
	cinder::gl::popMatrices();
}

void Viewer::renderTile(cinderColor tileColor, int tileSize)
{
	cinder::gl::color(tileColor);
	cinder::gl::drawSolidRect(cinder::Rectf(0, 0, tileSize, tileSize));
}

void Viewer::renderTimeline(cinderColor color, int startingX, int size, int markerX, int markerWidth)
{
	cinder::gl::pushMatrices();
	cinder::gl::color(color);
	cinder::gl::translate(startingX, 0);
	cinder::gl::drawSolidRect(cinder::Rectf(0, 0, size, timeLineHeight));
	cinder::gl::drawSolidRect(cinder::Rectf(0, 0, markerWidth, markerHeight));

	cinder::gl::translate(markerX, 0);
	cinder::gl::drawSolidRect(cinder::Rectf(0, 0, markerWidth, markerHeight));
	cinder::gl::popMatrices();

	cinder::gl::pushMatrices();
	cinder::gl::translate(startingX + size, 0);
	cinder::gl::drawSolidRect(cinder::Rectf(0, 0, markerWidth, markerHeight));
	cinder::gl::popMatrices();
}

void Viewer::renderPlantTimelines(std::vector<PlantVisual*> plants, double timepixelRelation, double currentYear)
{
	cinder::gl::pushMatrices();
	for (auto plant : plants){
		Segment<double> plantYears(plant->getSeedYear(), plant->getSeedYear() + plant->getMaxAge(), currentYear);
		int start = plantYears.getMin() * timepixelRelation;
		int size = plant->getMaxAge() * timepixelRelation;
		int computedYear = (plantYears.get() - plantYears.getMin()) * timepixelRelation;
		cinderColor color = plant->getTimelineColor();

		renderTimeline(color, start, size, computedYear, timeLineHeight);
		cinder::gl::translate(0, markerHeight + timeLineMargin);
	}
	cinder::gl::popMatrices();
}

CoordsInt Viewer::getGardenRenderingOffset(GardenVisual *garden)
{
	DimensionsInt halfSize = garden->getGardenPixelSize();
	return CoordsInt((windowSize - halfSize).x / 2, (windowSize - halfSize).y / 3);
}
