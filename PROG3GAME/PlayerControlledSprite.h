#ifndef PLAYERCONTROLLEDSPRITE_H
#define PLAYERCONTROLLEDSPRITE_H

#include "MovingSprite.h"

namespace GameEngine {
	class PlayerControlledSprite : public MovingSprite
	{
	public:
		~PlayerControlledSprite();
	protected:
		PlayerControlledSprite(int x, int y, const std::string spritePath);
	};
}
#endif
