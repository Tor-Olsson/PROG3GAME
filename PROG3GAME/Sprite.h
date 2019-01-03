#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "System.h"

namespace GameEngine {
	class Sprite
	{
	public:
		SDL_Rect getRectangle() const;
		void draw() const {};
		/*virtual void tick(SDL_Event event);
		virtual ~Sprite();*/
	protected:
		Sprite(int x, int y, int w, int h);
		void setWH(int w, int h);
	private:
		SDL_Rect rect;
		SDL_Surface* spritePicture;
	};
}

#endif