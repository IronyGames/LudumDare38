#pragma once

class GameStateManager;
class ImageFlyweight;
class FontFactory;
class InputController;
class Viewer;

class GameStateManagerBuilder {
public:
	GameStateManagerBuilder(ImageFlyweight *_images, FontFactory *_fonts, InputController* _input, Viewer *_viewer);
	GameStateManager* build();
private:
	ImageFlyweight* images;
	FontFactory* fonts;
	InputController* input;
	Viewer *viewer;
};