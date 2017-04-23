#pragma once

#include "Typedef.h"

class GardenLogic;
class GardenVisual;
class InventoryLogic;

class Level
{
public:
	Level( owner<GardenLogic> gardenLogic_, owner<InventoryLogic> inventoryLogic_ );
	~Level();

	GardenVisual*	getGardenVisual() const;
	GardenLogic*	getGardenLogic() const;
	InventoryLogic* getInventory() const;

private:
	GardenLogic* gardenLogic;
	GardenVisual* gardenVisual;

	InventoryLogic* inventoryLogic;
};