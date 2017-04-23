#pragma once
#include "IGameState.h"

class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;
class LevelBuilder;
class LevelManager;

class GameStateGame : public IGameState {
public:
	GameStateGame(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	String update() override;
	void draw() override;
	void onAnyKey();
private:
	Viewer *viewer;
	ImageFlyweight *images;
	FontFactory *fonts;
	bool hasClicked;
	LevelManager *levelManager;
};