#include "Sprite.h"

#include <iostream>

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

	void Sprite::changeSprite(const std::string spritePath) {
		SDL_Surface* spriteSurface = IMG_Load(spritePath.c_str());

		if (spriteSurface == NULL) {
			throw std::invalid_argument("Sprite-picture not found");
		}

		spriteTexture = SDL_CreateTextureFromSurface(system.getRenderer(), spriteSurface);
		spriteRectangle = { spriteRectangle.x, spriteRectangle.y, spriteSurface->w, spriteSurface->h };
		SDL_FreeSurface(spriteSurface);
	}


	bool Sprite::detectCollision(const std::vector<Sprite*> sprites) {
		for (Sprite* s : sprites) {
			
			if (this != s) {
				SDL_bool collision = SDL_HasIntersection(&getRectangle(), &s->getRectangle());

				if (collision) {
					pang = true;
					return true;
				}
			}
		}
		pang = false;
		return false;
	}

	bool Sprite::getCollision() {
		return pang;
	}

	void Sprite::draw() const {
		SDL_RenderCopy(system.getRenderer(), spriteTexture, NULL, &spriteRectangle);
	}

	void Sprite::setWH(int w, int h) {
		spriteRectangle.w = w;
		spriteRectangle.h = h;
	}

	void Sprite::setPosition(int x, int y) {
		spriteRectangle.x = x;
		spriteRectangle.y = y;
	}
	   
	SDL_Rect Sprite::getRectangle() const {
		return spriteRectangle;
	}

}
