#include "Controller.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Viewer.h"
#include "GardenVisual.h"
#include "PlantVisual.h"
#include "GardenLogic.h"
#include "PlantLogic.h"

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
	std::vector<IGardenEntityLogic*> pes = {
		new PlantLogic(EPlantType::k_tree, PlantPattern(), CoordsInt(2, 2), Year(30))
	};
	GardenLogic *gl = new GardenLogic(GardenRules(Segment<Year>(0,100,0), 4, 6), pes);
	g = new GardenVisual(gl);
}

void Controller::mouseDown( MouseEvent event )
{
}

void Controller::update()
{
}

void Controller::draw()
{
	viewer->begin();
	viewer->render(g);
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
