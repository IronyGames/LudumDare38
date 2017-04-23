#pragma once
#include "IGameState.h"

class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;

class GameStateMenu : public IGameState {
public:
	GameStateMenu(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	String update() override;
	void draw() override;
	void onAnyKey();
private:
	Viewer *viewer;
	Image background;
	FontFactory *fonts;
	bool hasClicked;
};