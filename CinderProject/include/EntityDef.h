#pragma once
#include "GardenEntityPattern.h"

class EntityDef
{
public:
	EntityDef( GardenEntityPattern pattern_, std::string type_, bool isStatic_ );

	bool operator<( const EntityDef& other ) const;

	const GardenEntityPattern	gardenEntityPattern;
	const std::string type;
	const bool isStatic = true;
};