#include "GameStateGame.h"

#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "Viewer.h"
#include "LevelBuilder.h"
#include "LevelManager.h"
#include "InputController.h"
#include "GardenLogic.h"
#include "GardenVisual.h"

GameStateGame::GameStateGame(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer)
: images(_images)
, fonts(_fonts)
, viewer(_viewer)
, input(_input)
, hasClicked(false)
{
	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("../resources/levels.json");

	levelManager = new LevelManager(std::move(levels));

	input->Dispatcher<GardenEventListener>::RegisterListener(levelManager);

	const auto dimensions = levelManager->getGardenLogic()->getDimensions();
	input->onLevelGridChanged(dimensions.witdh, dimensions.height);

	const auto gardenPixelSize = levelManager->getGardenVisual()->getGardenPixelSize();
	input->onWorldDimensionsChange(gardenPixelSize.x, gardenPixelSize.y);
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

GameStateGame::~GameStateGame()
{
	input->Dispatcher<GardenEventListener>::UnregisterListener(levelManager);
}
