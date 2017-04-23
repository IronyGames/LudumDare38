#include "InventoryLogic.h"

InventoryLogic::InventoryLogic()
{
	selectedEntity = catalog.end();
}

void InventoryLogic::addEntity( EntityDef entity, unsigned count )
{
	catalog[entity] += count;

	if(selectedEntity == catalog.end())
	{
		selectedEntity = catalog.find( entity );
	}
}

std::map<EntityDef, int> InventoryLogic::getCatalog() const
{
	return catalog;
}

void InventoryLogic::selectEntity( EntityDef entityDef )
{
	auto it = catalog.find(entityDef);
	if (it != catalog.end() )
	{
		selectedEntity = it;
	}
}

void InventoryLogic::unselect()
{
	selectedEntity = catalog.end();
}

boost::optional<EntityDef> InventoryLogic::extractSelectedEntityDef() const
{
	if ( selectedEntity != catalog.end() && selectedEntity->second > 0)
	{
		--selectedEntity->second;
		return selectedEntity->first;
	}

	return boost::none;
}
