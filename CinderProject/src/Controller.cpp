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
	std::vector<IGardenEntityLogic*> pes = {
		new PlantLogic(EPlantType::k_tree, PlantPattern(), CoordsInt(2, 2), Year(30))
	};
	GardenLogic *gl = new GardenLogic(GardenRules(Segment<Year>(0,100,0), 4, 6), pes);
	g = new GardenVisual(gl, imgs);


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
}

void Controller::draw()
{
	viewer->begin();
	viewer->render(g);
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
