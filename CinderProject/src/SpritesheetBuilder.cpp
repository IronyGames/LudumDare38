#include "SpritesheetBuilder.h"
#include "Spritesheet.h"
#include "cinder\app\AppBase.h"
#include "ImageFlyweight.h"
#include "Animation2D.h"

SpritesheetBuilder::SpritesheetBuilder( ImageFlyweight *_images )
:images(_images)
{
	load();
}


void SpritesheetBuilder::load()
{
	
}
