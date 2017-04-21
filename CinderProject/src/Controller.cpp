#include "Controller.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Viewer.h"

using namespace ci;
using namespace ci::app;
using namespace std;

void Controller::setup()
{
	viewer = new Viewer();
	setFrameRate(viewer->getFramesPerSecond());
	setWindowSize(viewer->getWindowSize());
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
	viewer->end();
}

CINDER_APP( Controller, RendererGl )
