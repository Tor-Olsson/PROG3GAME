#include "Sprite.h"

namespace GameEngine {

	Sprite::Sprite(int x, int y, const std::string spritePath) {
		SDL_Surface* spriteSurface = IMG_Load(spritePath.c_str());
		if (spriteSurface == NULL) {
			throw std::invalid_argument("Sprite-picture not found");
		}
		w = system.getWidth();
		h = system.getHeight();
		spriteTexture = SDL_CreateTextureFromSurface(system.getRenderer(), spriteSurface);
		spriteRectangle = { x, y, spriteSurface->w, spriteSurface->h };
		SDL_FreeSurface(spriteSurface);
	}

	void Sprite::changeSprite(const std::string spritePath) {
		SDL_Surface* spriteSurface = IMG_Load(spritePath.c_str());
		SDL_DestroyTexture(spriteTexture);
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
					collisioned = s;
					return true;
				}
			}
		}
		collisioned = nullptr;
		return false;
	}

	Sprite* Sprite::getCollision() {
		return collisioned;
	}

	void Sprite::draw() const {
		SDL_RenderCopy(system.getRenderer(), spriteTexture, NULL, &spriteRectangle);
	}

	bool Sprite::outOfScreen() {
		if (spriteRectangle.x > w || spriteRectangle.x < 0)
			return true;
		if (spriteRectangle.y > h || spriteRectangle.y < 0)
			return true;
		return false;
	}

	void Sprite::setPosition(int x, int y) {
		spriteRectangle.x = x;
		spriteRectangle.y = y;
	}

	SDL_Rect Sprite::getRectangle() const {
		return spriteRectangle;
	}
}
