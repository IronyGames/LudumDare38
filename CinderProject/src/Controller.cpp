#include "Controller.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Viewer.h"
#include "GardenVisual.h"
#include "PlantVisual.h"
#include "GardenLogic.h"
#include "PlantLogic.h"
#include "LevelManager.h"
#include "InputController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Controller::setup()
{
	viewer = new Viewer();
	setFrameRate(viewer->getFramesPerSecond());
	setWindowSize(viewer->getWindowSize());
	std::vector<IGardenEntityLogic*> pes = {
		new PlantLogic(EPlantType::k_tree, PlantPattern(), CoordsInt(2, 2), Year(56)),
		new PlantLogic(EPlantType::k_tree, PlantPattern(), CoordsInt(0, 4), Year(23)),
		new PlantLogic(EPlantType::k_tree, PlantPattern(), CoordsInt(1, 5), Year(7)),
	};
	gardenLogic = new GardenLogic(GardenRules(Segment<Year>(0,100,0), 4, 6), pes);
	g = new GardenVisual(gardenLogic);
	
	levelManager = new LevelManager();
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
	viewer->render(g);
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
