#pragma once
#include "IGameState.h"
#include "InputController.h"

class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;

class GameStateInstructions : public IGameState, public InputEventListener {
public:
	GameStateInstructions(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	String update() override;
	void draw() override;
	void onAnyKey() override;
private:
	Viewer *viewer;
	Image background;
	FontFactory *fonts;
	bool hasClicked;
	void renderTextLine(String text, int height);
};