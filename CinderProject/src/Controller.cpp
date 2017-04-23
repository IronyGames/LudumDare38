#include "Controller.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Viewer.h"
#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "InputController.h"
#include "GameStateManagerBuilder.h"
#include "GameStateManager.h"


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
}

CINDER_APP( Controller, RendererGl )
