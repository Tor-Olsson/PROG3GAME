#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H

#include "Sprite.h"

namespace GameEngine {
	class MovingSprite : public Sprite
	{
	public:
		virtual void tick(SDL_Event& event) {};
		virtual ~MovingSprite();
	
	protected:
		MovingSprite(int x, int y, const std::string spritePath);
	};
}
#endif