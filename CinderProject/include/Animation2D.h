#pragma once

#include "Segment.h"
#include "Typedef.h"

class Animation2D{
public:
	Animation2D();
	Animation2D(Image _image);
	Animation2D(Image _image, DimensionsInt *_tilePixelSize,
		CoordsInt *_initialOffset, Segment<int> *_tileSequence, bool _loops);

	bool hasAnimationFinished();

	void updateAnimation(); //returns whether the animation's finished / will loop next frame
	void resetAnimation();
	
	void changeLooping(bool _loops);

	Image getImage();
	DimensionsInt* getTileSize();
	CoordsInt* getOffset();
	int getCurrentTile();

	int tileColumns;

private:
	Segment<int> *tileSequence;
	DimensionsInt *tilePixelSize;
	CoordsInt *initialOffset;
	bool loops;

	Image image;
};
