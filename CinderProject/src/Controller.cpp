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

using namespace ci;
using namespace ci::app;
using namespace std;

void Controller::setup()
{
	viewer = new Viewer();
	setFrameRate(viewer->getFramesPerSecond());
	setWindowSize(viewer->getWindowSize());

	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("path");

	levelManager = new LevelManager( std::move(levels) );
	inputController = new InputController( getWindow() );
	inputController->RegisterEventListener( levelManager );
}

void Controller::mouseDown( MouseEvent event )
{
}

void Controller::update()
{
	bool isConnected = levelManagerEventListenerConnection.isConnected();
}

void Controller::draw()
{
	viewer->begin();
	viewer->render( levelManager->getGardenVisual() );
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
