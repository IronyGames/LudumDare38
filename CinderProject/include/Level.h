#pragma once

#include "Typedef.h"

class GardenLogic;
class GardenVisual;

class Level
{
public:
	Level( owner<GardenLogic> gardenLogic_, owner<GardenVisual> gardenVisual_ );
	~Level();

	GardenVisual*	getGardenVisual() const;
	GardenLogic*	getGardenLogic() const;

private:
	GardenLogic* gardenLogic;
	GardenVisual* gardenVisual;
};