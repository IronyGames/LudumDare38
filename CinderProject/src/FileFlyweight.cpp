#include "FileFlyweight.h"
#include <string>

FileFlyweight::FileFlyweight()
:dataLocator("./data.json")
, configLocator("configuration.json")
{
	String path = getJsonData(dataLocator)->getChild("data_folder").getValue();
	cinder::JsonTree::Container config = getJsonData(path + configLocator)->getChildren();
	for (auto it = config.begin(); it != config.end(); it++){
		dataToFile[it->getKey()] = path + it->getValue();
	}
}