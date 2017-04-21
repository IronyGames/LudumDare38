#include "Spritesheet.h"
#include "Animation2D.h"

Spritesheet::Spritesheet()
:Spritesheet(std::map<String, Animation2D*>(), CoordsInt())
{
}

Spritesheet::Spritesheet(std::map<String, Animation2D*> _animations, CoordsInt _position)
: Spritesheet(_animations, _position, "idle")
{
}

Spritesheet::Spritesheet(std::map<String, Animation2D*> _animations, CoordsInt _position, String _currentAnimation)
: animations(_animations)
, currentAnimation(_currentAnimation)
, position(_position)
{

}

Spritesheet::~Spritesheet()
{
	animations.clear();
}

void Spritesheet::changeAndRestartAnimation(String _animationName)
{
	if (!doesAnimationExist(_animationName)){
		String msg = "No such animation " + _animationName;
		throw new std::exception(msg.c_str());
	}
	currentAnimation = _animationName;
	resetCurrent();
}

bool Spritesheet::hasCurrentAnimationFinished()
{
	return getCurrentAnimation()->hasAnimationFinished();
}

Animation2D* Spritesheet::getCurrentAnimation()
{
	if (!doesAnimationExist(currentAnimation)){
		
		return new Animation2D();
	}

	return animations.at(currentAnimation);
}

void Spritesheet::update()
{
	animations.at(currentAnimation)->updateAnimation();
}

void Spritesheet::resetAll()
{
	for (auto it = animations.begin(); it != animations.end(); it++){
		it->second->resetAnimation();
	}
}

void Spritesheet::resetCurrent()
{
	getCurrentAnimation()->resetAnimation();
}

bool Spritesheet::doesAnimationExist(String _animationName)
{
	return animations.find(_animationName) != animations.end();
}

/*

void Spritesheet::draw(bool _fromCenter)
{
	cinder::gl::pushMatrices();
	cinder::gl::translate(offset->getTranslation());
	cinder::gl::rotate(offset->getRotation());
	cinder::gl::scale(offset->getScale());
	getCurrentAnimation()->draw(_fromCenter);
	cinder::gl::popMatrices();
}
*/
