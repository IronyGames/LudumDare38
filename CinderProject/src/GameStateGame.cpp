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
	deactivate();
	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("../resources/levels.json", images);

	levelManager = new LevelManager(std::move(levels));
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
	
}

void GameStateGame::activate()
{
	input->Dispatcher<GardenEventListener>::RegisterListener(levelManager);

	const auto dimensions = levelManager->getGardenLogic()->getDimensions();
	input->onLevelGridChanged(dimensions.witdh, dimensions.height);

	const auto gardenPixelSize = levelManager->getGardenVisual()->getGardenPixelSize();
	input->onWorldDimensionsChange(gardenPixelSize.x, gardenPixelSize.y);
}

void GameStateGame::deactivate()
{
	input->Dispatcher<GardenEventListener>::UnregisterListener(levelManager);
}
