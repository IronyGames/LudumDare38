#pragma once
#include "IGameState.h"

class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;

class GameStateEnd : public IGameState {
public:
	GameStateEnd(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	String update() override;
	void draw() override;
	void activate() override;
	void deactivate() override;
private:
	Viewer *viewer;
	Image background;
	FontFactory *fonts;
};