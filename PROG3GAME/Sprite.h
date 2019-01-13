#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "System.h"

namespace GameEngine {
	class Sprite
	{
	public:
		Sprite(int x, int y, const std::string spritePath);
		SDL_Rect getRectangle() const;
		Sprite* getInstance(int x, int y, const std::string spritePath);
		void draw() const;
		void tick();
		 ~Sprite() {};
	protected:

		void setWH(int w, int h);
	private:
		SDL_Rect spriteRectangle;
		SDL_Surface* spriteSurface;
		SDL_Texture* spriteTexture;
	};
}

#endif