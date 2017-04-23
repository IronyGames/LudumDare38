#pragma once

#include "Level.h"
#include <vector>

class IGardenGoalLogic;
class GoalData;

class LevelBuilder
{
public:
	std::vector<Level> LoadLevels( std::string path, ImageFlyweight *images );

private:
	IGardenGoalLogic* BuildGoal( const GoalData& goalData );
	std::vector<IGardenGoalLogic*> BuildGoals( std::vector<GoalData> goalsData );
};