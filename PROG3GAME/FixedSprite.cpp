#include "FixedSprite.h"

namespace GameEngine {

	FixedSprite::FixedSprite(int x, int y, const std::string spritePath) : Sprite (x, y, spritePath)
	{
	}

	void FixedSprite::tick() {
		//It's fixed, so nothing?
	}

	FixedSprite* FixedSprite::getInstance(int x, int y, const std::string spritePath) {
		return new FixedSprite(x, y, spritePath);
	}


	FixedSprite::~FixedSprite()
	{
	}

}
