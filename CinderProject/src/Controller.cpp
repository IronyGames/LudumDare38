#include "Controller.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Viewer.h"
#include "GardenVisual.h"
#include "PlantVisual.h"
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
	PlantVisual* p = new PlantVisual(CoordsInt(1, 1), std::vector<CoordsInt>({ CoordsInt(1, 0), CoordsInt(2, 0), CoordsInt(0, -1) }));
	std::vector<PlantVisual*> ps = { p };
	g = new GardenVisual(DimensionsInt(5, 5), ps);


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
