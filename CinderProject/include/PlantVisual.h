#pragma once

#include "Typedef.h"

class PlantVisual{
public:
	PlantVisual(CoordsInt _seed, std::vector<CoordsInt> _grownTiles);
	std::vector<CoordsInt> getGrownTiles() const;
	CoordsInt getSeed() const;
	cinderColor getPlantTile(CoordsInt tile);
	cinderColor getSeedTile();
private:
	CoordsInt m_seed;
	std::vector<CoordsInt> m_grownTiles;
	cinderColor m_growthColor;
	cinderColor m_seedColor;
};
