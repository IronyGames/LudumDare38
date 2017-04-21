#include "GameFileLoader.h"

GameFileLoader::GameFileLoader()
{
}

CinderJson* GameFileLoader::getJsonData(String _filePath)
{
	return new CinderJson(getFile(_filePath));
}

CinderDataSource GameFileLoader::getFile(String _filePath)
{
	return cinder::loadFile(_filePath);
}
