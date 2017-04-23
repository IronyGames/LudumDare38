#pragma once

#include "cinder/app/App.h"
#include "Typedef.h"

class Viewer;
class GardenVisual;
class GardenLogic;
class LevelManager;
class InputController;
class GameStateManager;

class Controller : public cinder::app::App {
public:
	void setup() override;
	void mouseDown(cinder::app::MouseEvent event) override;
	void update() override;
	void draw() override;
private:
	Viewer *viewer;
	GameStateManager *states;

	owner<LevelManager>		levelManager;
	owner<InputController>	inputController;
};