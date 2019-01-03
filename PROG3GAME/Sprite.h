#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

namespace GameEngine {
	class Sprite
	{
	public:
		Sprite();
		void draw() const;
		void tick(SDL_Event event);
		~Sprite();
		
	private:
		SDL_Rect rect;
		SDL_Surface spritePicture;
	};
}

#endif