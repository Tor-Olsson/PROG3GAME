#ifndef PLAYERCONTROLLEDSPRITE_H
#define PLAYERCONTROLLEDSPRITE_H

#include "MovingSprite.h"

namespace GameEngine {
	class PlayerControlledSprite : public MovingSprite
	{
	public:
		virtual void mouseDown(const SDL_Event& event) {};
		virtual void mouseUp(const SDL_Event& event) {};
		virtual void keyDown(const SDL_Event& event) {};
		virtual void keyUp(const SDL_Event& event) {};
		virtual void tick(const SDL_Event& event) = 0;
		~PlayerControlledSprite();
	protected:
		PlayerControlledSprite(int x, int y, const std::string spritePath);
	};
}
#endif
