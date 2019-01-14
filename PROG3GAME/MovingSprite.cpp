#include "MovingSprite.h"

namespace GameEngine {

	MovingSprite::MovingSprite(int x, int y, const std::string spritePath) : Sprite(x,y,spritePath)
	{
	}

	void MovingSprite::tick() {
		//do something
	}

	MovingSprite::~MovingSprite()
	{
	}

}