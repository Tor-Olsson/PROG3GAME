#ifndef FIXEDSPRITE_H
#define FIXEDSPRITE_H

#include "Sprite.h"

namespace GameEngine {
	class FixedSprite : public Sprite
	{
	public:

		/*
		* Returns a new static instance of this class
		* @param x the placement on the screen width
		* @param y placement on the screen height
		* @param spritePath path to the picture to be used
		*/
		static FixedSprite* getInstance(int x, int y, const std::string spritePath);
		
		/*
		Handles events in the game loop. Implemented as empty since fixed sprites usually don't do much.
		*/
		void tick(const SDL_Event& event) {};

		virtual ~FixedSprite();		

	protected:
		FixedSprite(int x, int y, const std::string spritePath);
	};
}
#endif

