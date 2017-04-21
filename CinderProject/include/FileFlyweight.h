#pragma once

#include "Typedef.h"
#include "GameFileLoader.h"
#include <utility>

class Enemy;

class FileFlyweight : public GameFileLoader{
private:
	std::map<String, String> dataToFile;
	String dataLocator;
	String configLocator;
public:
	FileFlyweight();
};