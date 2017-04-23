#include "EntityDef.h"

EntityDef::EntityDef( GardenEntityPattern pattern, std::string type_, bool isStatic_ )
	: gardenEntityPattern(pattern)
	, type(type_)
	, isStatic(isStatic_)
{}

bool EntityDef::operator<( const EntityDef& other ) const
{
	return type < other.type;
}
