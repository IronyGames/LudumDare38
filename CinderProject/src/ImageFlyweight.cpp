#include "ImageFlyweight.h"
#include "cinder\app\AppBase.h"

ImageFlyweight::ImageFlyweight(){}

Image ImageFlyweight::get(String path)
{
	if (storage.find(path) == storage.end()){
		storage[path] = createImage(path);
	}
	return storage[path];
}

Image ImageFlyweight::createImage(String path)
{
	Image out;
	out = out->create(cinder::loadImage(cinder::app::loadAsset(path)));
	out->setMagFilter(GL_NEAREST);
	out->setMinFilter(GL_NEAREST);
	return out;
}
