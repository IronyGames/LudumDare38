#pragma once

#include "cinder/app/App.h"
#include "Typedef.h"

class Viewer;
class GardenVisual;

class Controller : public cinder::app::App {
public:
	void setup() override;
	void mouseDown(cinder::app::MouseEvent event) override;
	void update() override;
	void draw() override;
private:
	Viewer *viewer;
	GardenVisual *g;
};