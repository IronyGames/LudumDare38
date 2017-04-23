#pragma once
#include "IGameState.h"
#include "InputController.h"

class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;
class InputController;

class GameStateMenu : public IGameState, public InputEventListener {
public:
	GameStateMenu(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	~GameStateMenu();
	String update() override;
	void draw() override;
	void onAnyKey() override;
	void activate();
	void deactivate();
private:
	Viewer *viewer;
	Image background;
	FontFactory *fonts;
	InputController *input;
	bool hasClicked, isActive;
};