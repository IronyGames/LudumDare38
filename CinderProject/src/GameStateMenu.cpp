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
	input->Dispatcher<InputEventListener>::RegisterListener(this);
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
	input->Dispatcher<InputEventListener>::UnregisterListener(this);
}

void GameStateMenu::activate()
{
	isActive = true;
}

void GameStateMenu::deactivate()
{
	isActive = false;
}
