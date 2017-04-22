#include "Level.h"

#include "GardenLogic.h"
#include "GardenVisual.h"

Level::Level( GardenLogic* gardenLogic_ )
	: gardenLogic( gardenLogic_ )
	, gardenVisual( new GardenVisual( gardenLogic ) )
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
