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
, tileSize(50)
, tileSeparator(5)
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

	int translation = tileSize + tileSeparator;
	DimensionsInt halfSize = getGardenSize(size);
	
	cinder::gl::pushMatrices();
	cinder::gl::translate((windowSize-halfSize) / 2);
	cinder::gl::pushMatrices();
	for (int r = 0; r < size.y; r++){
		cinder::gl::pushMatrices();
		for (int c = 0; c < size.x; c++){
			renderTile(garden->getSoilTile(CoordsInt(c, r)));
			cinder::gl::translate(translation, 0, 0);
		}
		cinder::gl::popMatrices();
		cinder::gl::translate(0, translation, 0);
	}
	cinder::gl::popMatrices();
	render(garden->getPlants());
	cinder::gl::popMatrices();
}

void Viewer::render(PlantVisual *plant)
{
	CoordsInt seedPosition = plant->getSeed();
	std::vector<CoordsInt> grownTiles = plant->getGrownTiles();
	
	cinder::gl::pushMatrices();
	cinder::gl::translate(getTileTranslation(seedPosition));
	renderTile(plant->getSeedTile());

	for (auto growth : grownTiles ){
		cinder::gl::pushMatrices();
		CoordsInt translation = getTileTranslation(growth);
		cinder::gl::translate(translation);
		renderTile(plant->getPlantTile(growth));
		cinder::gl::popMatrices();
	}
	cinder::gl::popMatrices();
}

void Viewer::render(std::vector<PlantVisual*> plants)
{
	for (auto plant = plants.begin(); plant != plants.end(); plant++){
		render(*plant);
	}
}

CoordsInt Viewer::getTileTranslation(CoordsInt tile)
{
	return tile * (tileSize + tileSeparator);
}

DimensionsInt Viewer::getGardenSize(DimensionsInt size)
{
	return getTileTranslation(size) - tileSeparator;
}

void Viewer::renderTile(cinderColor tileColor)
{
	cinder::gl::color(tileColor);
	cinder::gl::drawSolidRect(cinder::Rectf(0, 0, tileSize, tileSize));
}