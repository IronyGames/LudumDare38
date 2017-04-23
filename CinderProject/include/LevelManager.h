#pragma once
#include "InputController.h"
#include "Level.h"

#include <vector>

#include "cinder/Signals.h"


class WindowObserver;
class IGardenEntityLogic;
class InventoryLogic;

class LevelManager : public GardenEventListener
{
public:
	LevelManager( std::vector<Level> levels_ );
	~LevelManager();

	cinder::signals::Connection doOnLevelCompleted( std::function<void(int)> onLevelCompleted );

	GardenVisual*	getGardenVisual() const;
	GardenLogic*	getGardenLogic() const;
	InventoryLogic* getInventory() const;

	void selectLevel(unsigned level);
	int getTotalLevelCount() const;
	int getCurrentLevel() const;

private:
	// EventListener
	void onTimeChanged( Year deltaYear ) override;
// 	void onRewindTime() override;
// 	void onForwardTime() override;
	void onAddEntity(CoordsInt tile) override;
	void onRemoveEntity(CoordsInt tile) override;
  
	std::vector<Level> levels;
	size_t currentLevel = 0;


	cinder::signals::Signal<void(int)> onLevelCompleteSignal;
};