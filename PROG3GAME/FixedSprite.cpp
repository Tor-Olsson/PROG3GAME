#include "FixedSprite.h"

namespace GameEngine {

	FixedSprite::FixedSprite(int x, int y) : Sprite(x, y, 0, 0)
	{
	}

	void FixedSprite::draw() const {
		SDL_RenderCopy(system.getRenderer(), texture, NULL, &getRectangle());
	}
	FixedSprite::~FixedSprite()
	{
	}

}
