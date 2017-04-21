#pragma once

#include "Typedef.h"

class Animation2D;
class ImageFlyweight;

typedef std::vector<Animation2D*> FontText;

class FontFactory{
private:
	ImageFlyweight *images;
	std::map<char, Animation2D*> letters;
	Animation2D* getLetter(char l);
public:
	FontFactory();
	FontFactory(ImageFlyweight *_images);
	FontText* getText(String _text);
	void load();
};