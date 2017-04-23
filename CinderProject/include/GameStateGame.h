#pragma once
#include "IGameState.h"
#include "cinder/Signals.h"
#include "InputController.h"

class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;
class LevelBuilder;
class LevelManager;
class InputController;

class GameStateGame : public IGameState, public InputEventListener
{
public:
	GameStateGame(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	~GameStateGame();
	String update() override;
	void draw() override;
	void onAnyKey() override;
	void activate() override;
	void deactivate() override;
private:

	void onLevelComplete(int level);

	Viewer *viewer;
	ImageFlyweight *images;
	FontFactory *fonts;
	LevelManager *levelManager;
	InputController *input;
	Image background;

	Image levelCompleteImage;
	bool isLevelCompleteState = false;
	bool isGameCompleted = false;

	cinder::signals::ScopedConnection onLevelCompleteConnection;
};