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

	levelManager = new LevelManager( std::move(levels) );
	inputController = new InputController( getWindow() );

	inputController->RegisterListener( levelManager );

	const auto dimensions = levelManager->getGardenLogic()->getDimensions();
	inputController->onLevelGridChanged( dimensions.witdh, dimensions.height );

	const auto gardenPixelSize = levelManager->getGardenVisual()->getGardenPixelSize();
	inputController->onWorldDimensionsChange( gardenPixelSize.x, gardenPixelSize.y );
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
