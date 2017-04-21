#pragma once

#include "Typedef.h"

class ImageFlyweight{
private:
	std::map<String, Image> storage;
	Image createImage(String path);
public:
	ImageFlyweight();
	Image get(String path);
	
};