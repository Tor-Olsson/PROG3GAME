#ifndef PLAYERCONTROLLEDSPRITE_H
#define PLAYERCONTROLLEDSPRITE_H

#include "MovingSprite.h"

namespace GameEngine {
	class PlayerControlledSprite : public MovingSprite
	{
	public:


		
		/*
		Handles events in the game loop. Implementation forced to subclasses
		*/
		virtual void tick(const SDL_Event& event) = 0;
		virtual ~PlayerControlledSprite();
	protected:
		PlayerControlledSprite(int x, int y, const std::string spritePath);
	};
}
#endif
