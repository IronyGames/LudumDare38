#pragma once

#include "Typedef.h"
#include "Segment.h"

#include <unordered_map>
#include <string>
#include "GardenEntityPattern.h"

struct GardenInitializationData
{
	GardenInitializationData() = default;
	GardenInitializationData(Segment<Year> _timeline, unsigned _gardenWidth, unsigned _gardenHeight);

	Segment<Year> timeline;

	unsigned gardenWidth = 0;
	unsigned gardenHeight = 0;

	struct Entity
	{
		std::string name;
		Year age;
	};
	std::unordered_map<CoordsInt, Entity> initialEntities;
};