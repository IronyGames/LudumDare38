#include "Controller.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Viewer.h"
#include "GardenVisual.h"
#include "PlantVisual.h"
#include "LevelManager.h"
#include "InputController.h"
#include "GardenLogic.h"
#include "PlantLogic.h"
#include "LevelManager.h"
#include "InputController.h"
#include "LevelBuilder.h"
#include "GameStateManagerBuilder.h"
#include "GameStateManager.h"
#include "ImageFlyweight.h"
#include "FontFactory.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Controller::setup()
{
	viewer = new Viewer();
	ImageFlyweight *images = new ImageFlyweight();
	FontFactory *fonts = new FontFactory(images);
	inputController = new InputController(getWindow());

	setFrameRate(viewer->getFramesPerSecond());
	setWindowSize(viewer->getWindowSize());

	GameStateManagerBuilder stateBuilder(images, fonts, inputController, viewer);
	states = stateBuilder.build();

	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("../resources/levels.json");

	levelManager = new LevelManager( std::move(levels), viewer );
	
	inputController->RegisterEventListener( levelManager );
}

void Controller::mouseDown( MouseEvent event )
{
}

void Controller::update()
{
	states->update();
}

void Controller::draw()
{
	states->draw();
/*
	viewer->begin();
	viewer->render( levelManager->getGardenVisual() );
	viewer->end();*/
}

CINDER_APP( Controller, RendererGl )
