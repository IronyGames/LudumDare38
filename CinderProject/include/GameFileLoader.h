#pragma once

#include "Typedef.h"
class GameFileLoader{
public:
	GameFileLoader();
protected:
	CinderJson* getJsonData(String _filePath);
	CinderDataSource getFile(String _filePath);
};