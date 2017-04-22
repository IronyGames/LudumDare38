#pragma once

#include "Typedef.h"
#include "Segment.h"

struct GardenRules
{
	GardenRules() = default;
	GardenRules(Segment<Year> _timeline, unsigned _gardenWidth, unsigned _gardenHeight);

	Segment<Year> timeline;

	unsigned gardenWidth = 0;
	unsigned gardenHeight = 0;
};