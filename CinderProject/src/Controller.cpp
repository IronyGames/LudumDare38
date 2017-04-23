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
#include "LevelBuilder.h"
#include "ImageFlyweight.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Controller::setup()
{
	viewer = new Viewer();
	setFrameRate(viewer->getFramesPerSecond());
	setWindowSize(viewer->getWindowSize());

	ImageFlyweight *imgs = new ImageFlyweight();

	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("path", imgs);

	levelManager = new LevelManager( std::move(levels) );
	inputController = new InputController( getWindow() );
	levelManagerEventListenerConnection = inputController->RegisterEventListener( levelManager );
}

void Controller::mouseDown( MouseEvent event )
{
}

void Controller::update()
{
	bool isConnected = levelManagerEventListenerConnection.isConnected();
	int a = 0;
	
}

void Controller::draw()
{
	viewer->begin();
	viewer->render( levelManager->getGardenVisual() );
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
