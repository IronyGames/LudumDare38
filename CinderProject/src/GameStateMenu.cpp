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
	hasClicked = true;
}

GameStateMenu::~GameStateMenu()
{
	input->Dispatcher<InputEventListener>::UnregisterListener(this);
}
