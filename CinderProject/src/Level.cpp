#include "Level.h"

#include "GardenLogic.h"
#include "GardenVisual.h"

Level::Level( GardenLogic* gardenLogic_, owner<InventoryLogic> inventoryLogic_ )
	: gardenLogic( gardenLogic_ )
	, gardenVisual( new GardenVisual( gardenLogic ) )
	, inventoryLogic( inventoryLogic_ )
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

InventoryLogic* Level::getInventory() const
{
	return inventoryLogic;
}
