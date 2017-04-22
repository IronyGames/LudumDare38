#pragma once
#include "InputController.h"

class LevelManager : public EventListener
{
public:

	// EventListener
	void onTimeChanged( Year deltaYear ) override;


private:
};