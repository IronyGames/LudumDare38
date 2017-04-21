#pragma once

#include "Typedef.h"
class Spritesheet;
class Job;
class ImageFlyweight;

class SpritesheetBuilder{
private:
	ImageFlyweight *images;
	void load();
public:
	SpritesheetBuilder(ImageFlyweight *_images);
};