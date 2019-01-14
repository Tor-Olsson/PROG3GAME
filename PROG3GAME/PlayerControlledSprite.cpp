#include "PlayerControlledSprite.h"

namespace GameEngine {

	PlayerControlledSprite::PlayerControlledSprite(int x, int y, const std::string spritePath) : MovingSprite(x, y, spritePath)
	{
	}


	PlayerControlledSprite::~PlayerControlledSprite()
	{
	}

}