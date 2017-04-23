#include "Level.h"

#include "GardenLogic.h"
#include "GardenVisual.h"

Level::Level( owner<GardenLogic> gardenLogic_, owner<GardenVisual> gardenVisual_ ) : gardenLogic( gardenLogic_ )
	, gardenVisual( gardenVisual_ )
{}

Level::~Level()
{}

GardenVisual* Level::getGardenVisual() const
{
	return gardenVisual;
}

GardenLogic* Level::getGardenLogic() const
{
	return gardenLogic;
}
