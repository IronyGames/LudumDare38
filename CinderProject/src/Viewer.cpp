#include "Viewer.h"
#include "Spritesheet.h"
#include "cinder\gl\wrapper.h"
#include "cinder\gl\draw.h"
#include "Animation2D.h"
#include "Typedef.h"
#include <vector>

Viewer::Viewer()
:windowSize(DimensionsInt(1280,720))
, zoom(1.0)
, framesPerSecond(60)
, backgroundColor(new cinderColor(0, 0.5, 0.5))
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
