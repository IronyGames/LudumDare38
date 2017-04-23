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
{
	deactivate();
	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("../resources/levels.json", images);
	background = images->get("../resources/game_bg.png");
	levelCompleteImage = images->get("../resources/level_complete_overlay.png");

	levelManager = new LevelManager(std::move(levels));
}

String GameStateGame::update()
{
	if (isGameCompleted)
	{
		return "win";
	}
	else if (isLevelCompleteState)
	{
		// disable level
		input->Dispatcher<GardenEventListener>::UnregisterListener( levelManager );
	}

	return "";
}

void GameStateGame::draw()
{
	viewer->begin();
	viewer->renderToWholeScreen(background);
	viewer->render(levelManager->getGardenVisual());
	if(isLevelCompleteState)
	{
		viewer->renderToWholeScreen(levelCompleteImage);
	}

	viewer->end();
}

void GameStateGame::onAnyKey()
{
	if(isLevelCompleteState)
	{
		activate();

		isLevelCompleteState = false;
		int currentLevel = levelManager->getCurrentLevel();
		levelManager->selectLevel( currentLevel + 1);
	}
}

GameStateGame::~GameStateGame()
{
	
}

void GameStateGame::activate()
{
	input->Dispatcher<InputEventListener>::RegisterListener( this );

	onLevelCompleteConnection = levelManager->doOnLevelCompleted( std::bind( &GameStateGame::onLevelComplete, this, std::placeholders::_1 ) );

	input->Dispatcher<GardenEventListener>::RegisterListener(levelManager);

	const auto dimensions = levelManager->getGardenLogic()->getDimensions();
	input->onLevelGridChanged(dimensions.witdh, dimensions.height);

	const auto gardenPixelSize = levelManager->getGardenVisual()->getGardenPixelSize();
	input->onWorldDimensionsChange(gardenPixelSize.x, gardenPixelSize.y);
}

void GameStateGame::deactivate()
{
	onLevelCompleteConnection.disconnect();
	input->Dispatcher<GardenEventListener>::UnregisterListener(levelManager);
	input->Dispatcher<InputEventListener>::UnregisterListener( this );
}

void GameStateGame::onLevelComplete( int level )
{
	if ( level + 1 >= levelManager->getTotalLevelCount())
	{
		isGameCompleted = true;
	}
	else
	{
		isLevelCompleteState = true;
	}
}
