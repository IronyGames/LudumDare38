#pragma once
#include "InputController.h"
#include "Level.h"
#include <vector>

class Viewer;
class IGardenEntityLogic;

class LevelManager : public EventListener
{
public:
	LevelManager( std::vector<Level> levels_, Viewer *_viewer );

	GardenVisual* getGardenVisual() const;
	GardenLogic* getGardenLogic() const;

private:
	Viewer* viewer;
	// EventListener
	void onTimeChanged( Year deltaYear ) override;
// 	void onRewindTime() override;
// 	void onForwardTime() override;
	void onAddEntity(CoordsInt mousePosition, const IGardenEntityLogic&) override;
	void onRemoveEntity(CoordsInt mousePosition) override;
  
	std::vector<Level> levels;
	size_t currentLevel = 0;

	CoordsInt getTile(CoordsInt mousePosition);
};