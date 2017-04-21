#pragma once
#include "Typedef.h"
#include <map>

class Animation2D;
class Spritesheet{
public:
	Spritesheet();
	Spritesheet(std::map<String, Animation2D*> _animations, CoordsInt _position);
	Spritesheet(std::map<String, Animation2D*> _animations, CoordsInt _position, String _currentAnimation);
	~Spritesheet();

	void changeAndRestartAnimation(String _animationName);
	bool hasCurrentAnimationFinished();
	Animation2D* getCurrentAnimation();

	void update();
	void resetAll();
	void resetCurrent();

	CoordsInt getPosition();
	
private:
	bool doesAnimationExist(String _animationName);
	
	String currentAnimation;
	std::map<String, Animation2D*> animations;

	CoordsInt position;
};

