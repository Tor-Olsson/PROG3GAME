#include "Sprite.h"

namespace GameEngine {

	Sprite::Sprite(int x, int y, const std::string spritePath)
	{
		spriteSurface = IMG_Load(spritePath.c_str());
		spriteTexture = SDL_CreateTextureFromSurface(system.getRenderer(), spriteSurface);
		spriteRectangle = { x, y, spriteSurface->w, spriteSurface->h };
		SDL_FreeSurface(spriteSurface);
		SDL_RenderCopy(system.getRenderer(), spriteTexture, NULL, &spriteRectangle);
	}

	void Sprite::draw() const {
		SDL_RenderCopy(system.getRenderer(), spriteTexture, NULL, &spriteRectangle);
	}

	Sprite* Sprite::getInstance(int x, int y, const std::string spritePath) {

	
		return new Sprite(0, 0, "nej");
	}

	void Sprite::tick() {
		spriteRectangle.y++;
	}

	SDL_Rect Sprite::getRectangle() const{
		return spriteRectangle;
	}

	void Sprite::setWH(int w, int h) {
		spriteRectangle.w = w;
		spriteRectangle.h = h;
	}

}
