#pragma once


#include "EntityDef.h"
#include "boost/optional/optional.hpp"

#include <map>

class IGardenEntityLogic;

class InventoryLogic
{
public:
	InventoryLogic();


	std::map<EntityDef, int> getCatalog() const;

	void selectEntity( EntityDef entityDef );
	void unselect();

	void addEntity( EntityDef entity, unsigned count );
	boost::optional<EntityDef> extractSelectedEntityDef() const;

private:
	std::map<EntityDef, int> catalog;
	std::map<EntityDef, int>::iterator selectedEntity;
};