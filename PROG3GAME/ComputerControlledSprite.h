#ifndef COMPUTERCONTROLLEDSPRITE_H
#define COMPUTERCONTROLLEDSPRITE_H

#include "MovingSprite.h"

namespace GameEngine {

	class ComputerControlledSprite : public MovingSprite
	{
	public:

		/*
		Handles events in the game loop. Implementation forced to subclasses (game designers decision what the sprites should do)
		*/
		virtual void tick(const SDL_Event& event) = 0;

		virtual ~ComputerControlledSprite();

	protected:
		ComputerControlledSprite(int x, int y, const std::string spritePath);
	};

}
#endif
