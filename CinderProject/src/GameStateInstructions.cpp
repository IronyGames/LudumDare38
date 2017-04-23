#include "GameStateInstructions.h"
#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "Viewer.h"
#include "cinder\gl\wrapper.h"

GameStateInstructions::GameStateInstructions(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer)
:background(_images->get("../resources/menu_instructions.png"))
, fonts(_fonts)
, viewer(_viewer)
, hasClicked(false)
, input(_input)
{
	deactivate();
}

String GameStateInstructions::update()
{
	if (hasClicked){
		return "game";
	}
	return "";
}

void GameStateInstructions::draw()
{
	DimensionsInt* size = fonts->getCharSize();
	viewer->begin();
	viewer->renderToWholeScreen(background);
	cinder::gl::pushMatrices();
	cinder::gl::scale(3, 3);
	cinder::gl::translate(size->x, size->y);
	renderTextLine("You have your little patch of land!", size->y);
	renderTextLine("Create your little own worlds of life!", size->y);
	renderTextLine("Left click plants, right click unplant", size->y);
	renderTextLine("Left and right arrows forward or rewind time", size->y);
	renderTextLine("Complete the vegetation objectives at the.", size->y);
	renderTextLine("end of the time to win! Remember, you.", size->y);
	renderTextLine("can move through time to observe the growth!", size->y);
	cinder::gl::popMatrices();
	viewer->end();
}

void GameStateInstructions::onAnyKey()
{
	if (isActive){
		hasClicked = true;
	}
}

void GameStateInstructions::renderTextLine(String text, int height)
{
	viewer->render(fonts->getText(text));
	cinder::gl::translate(0, 2*height);
}

GameStateInstructions::~GameStateInstructions()
{
	
}

void GameStateInstructions::activate()
{
	input->Dispatcher<InputEventListener>::RegisterListener( this );
	isActive = true;
}

void GameStateInstructions::deactivate()
{
	input->Dispatcher<InputEventListener>::UnregisterListener( this );
	isActive = false;
}
