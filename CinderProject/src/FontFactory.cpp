#include "FontFactory.h"
#include "ImageFlyweight.h"
#include "Segment.h"
#include "Animation2D.h"
#include <math.h>

FontFactory::FontFactory()
{

}

FontFactory::FontFactory(ImageFlyweight *_images)
:images(_images)
{
	load();
}

FontText* FontFactory::getText(String _text)
{
	//TODO: ensure pointing at std vectors without clearing does not lead to memory leaks
	FontText* out = new FontText();

	for (int i = 0; i < _text.length(); i++){
		out->push_back(getLetter(_text.at(i)));
	}

	return out;
}

void FontFactory::load()
{
	charSize = new DimensionsInt(8, 7);

	Image font = images->get("../resources/fonts.png");

	int columns = 10;

	String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-.!?',0123456789 ";

	for (int i = 0; i < characters.length(); i++){
		int x = i, y = 0;
		if (x >= columns){
			y = floor(x / columns);
			x %= columns;
		}
				
		DimensionsInt *offset = new DimensionsInt(x*charSize->x, y*charSize->y);
		Animation2D *a = new Animation2D(font, charSize, offset, new Segment<int>(0, 0, 0), false);
		letters[characters.at(i)] = a;
	}
}

Animation2D* FontFactory::getLetter(char l)
{
	if (letters.find(l) == letters.end()){
		String msg = "No such Letter " + l;
		throw new std::exception(msg.c_str());
	}
	return letters.at(l);
}

DimensionsInt* FontFactory::getCharSize()
{
	return charSize;
}
