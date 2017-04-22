#include "PlantVisual.h"

PlantVisual::PlantVisual(CoordsInt _seed, std::vector<CoordsInt> _grownTiles)
:m_seed(_seed)
, m_grownTiles(_grownTiles)
, m_growthColor(cinderColor(0.286, 0.475, 0.161))
, m_seedColor(cinderColor(0.42, 0.659, 0.263))
{

}

CoordsInt PlantVisual::getSeed() const {
	return m_seed;
}

std::vector<CoordsInt> PlantVisual::getGrownTiles() const {
	return m_grownTiles;
}

cinderColor PlantVisual::getPlantTile(CoordsInt tile)
{
	return m_growthColor;
}

cinderColor PlantVisual::getSeedTile()
{
	return m_seedColor;
}
