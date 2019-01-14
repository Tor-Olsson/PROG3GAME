#include "Sprite.h"

namespace GameEngine {

	Sprite::Sprite(int x, int y, const std::string spritePath)	{
		SDL_Surface* spriteSurface = IMG_Load(spritePath.c_str());

		if (spriteSurface == NULL) {
			throw std::invalid_argument("Sprite-picture not found");		
		}

		spriteTexture = SDL_CreateTextureFromSurface(system.getRenderer(), spriteSurface);
		spriteRectangle = { x, y, spriteSurface->w, spriteSurface->h };
		SDL_FreeSurface(spriteSurface);
	}

	void Sprite::draw() const {
		SDL_RenderCopy(system.getRenderer(), spriteTexture, NULL, &spriteRectangle);
	}

	void Sprite::setWH(int w, int h) {
		spriteRectangle.w = w;
		spriteRectangle.h = h;
	}
	   
	SDL_Rect Sprite::getRectangle() const {
		return spriteRectangle;
	}

}
