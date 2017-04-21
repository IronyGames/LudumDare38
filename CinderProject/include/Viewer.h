#pragma once

#include "Typedef.h"

class Animation2D;
class Spritesheet;
class StateProperties;
class Enemy;
class Hero;
class Battle;

class Viewer{
private:
	void renderAnimation2D(Animation2D *animation);
	void renderSpritesheet(Spritesheet *sheet);
	DimensionsInt windowSize;
	float zoom;
	int framesPerSecond;
	cinderColor* backgroundColor;
public:
	Viewer();
	void render(std::vector<Animation2D*> *_text);
	DimensionsInt getWindowSize();
	int getFramesPerSecond();
	void begin();
	void end();
};
