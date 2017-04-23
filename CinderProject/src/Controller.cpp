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
	std::vector<IGardenEntityLogic*> pes = {
		new PlantLogic(GardenEntityPattern(), Year(56), CoordsInt(2, 2)),
		new PlantLogic(GardenEntityPattern(), Year(23), CoordsInt(3, 4)),
		new PlantLogic(GardenEntityPattern(), Year(7), CoordsInt(1, 5)),
	};
	gardenLogic = new GardenLogic(Segment<Year>(0, 100, 0), 13, 13, pes);
	g = new GardenVisual(gardenLogic);

	LevelBuilder levelBuilder;
	std::vector<Level> levels = levelBuilder.LoadLevels("path");

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
	gardenLogic->updateGardenDelta(0.08);
}

void Controller::draw()
{
	viewer->begin();
	viewer->render( levelManager->getGardenVisual() );
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
