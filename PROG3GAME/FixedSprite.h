#ifndef FIXEDSPRITE_H
#define FIXEDSPRITE_H

#include "Sprite.h"

namespace GameEngine {
	class FixedSprite : public Sprite
	{
	public:
		FixedSprite(int x, int y);
		~FixedSprite();
		void draw() const;

	private:
		SDL_Texture* texture;
	};

}

#endif