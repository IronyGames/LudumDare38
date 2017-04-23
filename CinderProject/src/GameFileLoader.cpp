#include "GameFileLoader.h"

GameFileLoader::GameFileLoader()
{
}

CinderJson GameFileLoader::getJsonData(String _filePath)
{
	return CinderJson(getFile(_filePath));
}

CinderDataSource GameFileLoader::getFile(String _filePath)
{
	CinderDataSource dataSource = cinder::loadFile( _filePath );
	assert( dataSource != nullptr );
	return dataSource;
}
