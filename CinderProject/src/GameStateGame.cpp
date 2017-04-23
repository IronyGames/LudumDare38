#include "GameStateGame.h"

#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "Viewer.h"
#include "LevelBuilder.h"
#include "LevelManager.h"

GameStateGame::GameStateGame(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer)
: images(_images)
, fonts(_fonts)
, viewer(_viewer)
, hasClicked(false)
{
	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("../resources/levels.json");

	levelManager = new LevelManager(std::move(levels), viewer);

	_input->RegisterEventListener(levelManager);
}

String GameStateGame::update()
{
	if (hasClicked){
		return "instructions";
	}
	return "";
}

void GameStateGame::draw()
{
	viewer->begin();
	viewer->render(levelManager->getGardenVisual());
	viewer->end();
}

void GameStateGame::onAnyKey()
{
	hasClicked = true;
}
