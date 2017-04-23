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
	~GameStateInstructions();
	String update() override;
	void draw() override;
	void onAnyKey() override;
	void activate() override;
	void deactivate() override;
private:
	Viewer *viewer;
	Image background;
	FontFactory *fonts;
	bool hasClicked;
	InputController *input;
	bool isActive;
	void renderTextLine(String text, int height);
};