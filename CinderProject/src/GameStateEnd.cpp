#include "GameStateEnd.h"

#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "Viewer.h"
#include "InputController.h"

GameStateEnd::GameStateEnd(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer)
:background(_images->get("../resources/ending_screen.png"))
, fonts(_fonts)
, viewer(_viewer)
{

}

String GameStateEnd::update()
{
	return "";
}

void GameStateEnd::draw()
{
	viewer->begin();
	viewer->renderToWholeScreen(background);
	viewer->end();
}

void GameStateEnd::activate()
{

}

void GameStateEnd::deactivate()
{

}
