#include "LevelManager.h"
#include "GardenLogic.h"
#include "GardenVisual.h"
#include "PlantLogic.h"
#include "PlantVisual.h"
#include "Viewer.h"

LevelManager::LevelManager(std::vector<Level> levels_, Viewer *_viewer) : levels(std::move(levels_)), viewer(_viewer)
{}

GardenVisual* LevelManager::getGardenVisual() const
{
	return levels[currentLevel].getGardenVisual();
}

GardenLogic* LevelManager::getGardenLogic() const
{
	return levels[currentLevel].getGardenLogic();
}

void LevelManager::onTimeChanged( Year deltaYear )
{
	GardenLogic* gardenLogic = getGardenLogic();
	gardenLogic->updateGardenDelta(deltaYear);

	GardenLogic::EvaluateGoalResult result = gardenLogic->evaluateGoal();
	assert( result.haveWon == false ); // oh now, you won
}

void LevelManager::onAddEntity( CoordsInt mousePosition, const IGardenEntityLogic& )
{
	CoordsInt clickedTile = getTile(mousePosition);
	if (clickedTile == CoordsInt(-1, -1)){
		return;
	}
	PlantLogic *nextSeed = new PlantLogic(GardenEntityPattern(), Year(300), Year(200), clickedTile, "test_plant");
	getGardenLogic()->addEntity(nextSeed);
}

void LevelManager::onRemoveEntity( CoordsInt mousePosition )
{
	CoordsInt clickedTile = getTile(mousePosition);
	if (clickedTile == CoordsInt(-1, -1)){
		return;
	}
	getGardenLogic()->unPlant(clickedTile);
}

CoordsInt LevelManager::getTile(CoordsInt mousePosition)
{
	DimensionsInt size = getGardenVisual()->getGardenSize();
	DimensionsInt pixelSize = getGardenVisual()->getGardenPixelSize();
	int translation = getGardenVisual()->getTileTranslation();
	CoordsInt renderingOffset = viewer->getGardenRenderingOffset(getGardenVisual()); //TODO:  

	CoordsInt mouseTile = (mousePosition - renderingOffset) / translation;
	if (mouseTile.x < 0 || mouseTile.x > size.x || mouseTile.y < 0 || mouseTile.y > size.y){
		mouseTile = CoordsInt(-1, -1);
	}

	return mouseTile;
}
