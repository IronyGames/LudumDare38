#include "GameStateManagerBuilder.h"
#include "GameStateManager.h"
#include "IGameState.h"
#include "GameStateGame.h"
#include "GameStateInstructions.h"
#include "GameStateEnd.h"
#include "ImageFlyweight.h"
#include "FontFactory.h"
#include "GameStateMenu.h"

GameStateManagerBuilder::GameStateManagerBuilder(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer)
:images(_images)
, fonts(_fonts)
, input(_input)
, viewer(_viewer)
{

}

GameStateManager* GameStateManagerBuilder::build()
{
	std::map<String, IGameState*> states;
	states["menu"] = new GameStateMenu(images, fonts, input, viewer);
	states["instructions"] = new GameStateInstructions(images, fonts, input, viewer);
	states["game"] = new GameStateGame(images, fonts, input, viewer);
	states["win"] = new GameStateEnd(images, fonts, input, viewer);

	//return new GameStateManager(states, "menu");
	return new GameStateManager(states, "game"); //debug
	
}
