#include "Animation2D.h"
#include "cinder/gl/gl.h"

Animation2D::Animation2D()
:Animation2D(Image(), new DimensionsInt(0, 0), 
	new CoordsInt(), new Segment<int>(0,1), false)
{
}

Animation2D::Animation2D(Image _image)
: Animation2D(_image, new DimensionsInt(_image->getWidth(), _image->getHeight()), 
	new CoordsInt(), new Segment<int>(0, 0), false)
{

}

Animation2D::Animation2D(Image _image, DimensionsInt *_tilePixelSize, 
	CoordsInt *_initialOffset, Segment<int> *_tileSequence, bool _loops)
: image(_image)
, tilePixelSize(_tilePixelSize)
, initialOffset(_initialOffset)
, tileSequence(_tileSequence)
, loops(_loops)
{
	if (image != nullptr){
		int imageWidth = image->getWidth();
		tileColumns = imageWidth / tilePixelSize->x;
	}
}

void Animation2D::updateAnimation()
{
	if (loops && tileSequence->isMax()){
		resetAnimation();
	}
	else{
		(*tileSequence) += 1;
	}
}

void Animation2D::changeLooping(bool _loops)
{
	loops = _loops;
}

void Animation2D::resetAnimation()
{
	tileSequence->setToMin();
}

bool Animation2D::hasAnimationFinished()
{
	return (!loops) && (tileSequence->isMax());
}

Image Animation2D::getImage()
{
	return image;
}

DimensionsInt* Animation2D::getTileSize()
{
	return tilePixelSize;
}

CoordsInt* Animation2D::getOffset()
{
	return initialOffset;
}

int Animation2D::getCurrentTile()
{
	return tileSequence->get();
}

/*

void Animation2D::draw( bool fromCenter / *= false* / )
{

	int w = ((current_frame + tile_offset) % image_columns) * tile_width;
	int h = ((current_frame + tile_offset) / image_columns) * tile_height;
	int px = (float)tile_width / 2.0f;
	int py = (float)tile_height / 2.0f;
	

	cinder::Area sub(
		w,				h, 
		w+tile_width,	h+tile_height
		);

	cinder::Rectf pos(
		(-px), (-py), 
		( px), ( py) 
	);
	
	Coords2Ddouble center = offset->getTranslation();
	if (!fromCenter){
		Coords2Ddouble centerDifference = (offset->getScale() * Coords2Ddouble(tile_width, tile_height));
		centerDifference /= 2;
		center += centerDifference;
	}
	

	cinder::gl::pushMatrices();
		cinder::gl::translate(center);
		/ *cinder::gl::translate(offset->getTranslation());* /
		cinder::gl::rotate(offset->getRotation());
		cinder::gl::scale(offset->getScale());
		//image->draw();
		cinder::gl::draw(image->get(), sub, pos);
	cinder::gl::popMatrices();
	
	/ *
	ORIGINAL CODE
	---------------------------------------------
	int row = current_frame / image_columns;
	int column = current_frame % image_columns;

	cinder::Area sub(
		column		*tile_width,
		row			*tile_height,
		(column + 1)*tile_width,
		(row + 1)	*tile_height);

	cinder::Rectf pos(
		(-(float)tile_width / 2.0f),
		(-(float)tile_height / 2.0f),
		((float)tile_width / 2.0f),
		((float)tile_height / 2.0f)
		);
	* /
}
*/