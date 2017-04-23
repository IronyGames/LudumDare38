#include "GameStateMenu.h"

#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "Viewer.h"
#include "Dispatcher.h"

GameStateMenu::GameStateMenu(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer)
:background(_images->get("../resources/menu.png"))
, fonts(_fonts)
, viewer(_viewer)
, hasClicked(false)
, input(_input)
{

	deactivate();
}

String GameStateMenu::update()
{
	if (hasClicked){
		return "instructions";
	}
	return "";
}

void GameStateMenu::draw()
{
	viewer->begin();
	viewer->renderToWholeScreen(background);
	viewer->end();
}

void GameStateMenu::onAnyKey()
{
	if (isActive){
		hasClicked = true;
	}
}

GameStateMenu::~GameStateMenu()
{
}

void GameStateMenu::activate()
{
	input->Dispatcher<InputEventListener>::RegisterListener( this );
	isActive = true;
}

void GameStateMenu::deactivate()
{
	input->Dispatcher<InputEventListener>::UnregisterListener( this );
	isActive = false;
}
