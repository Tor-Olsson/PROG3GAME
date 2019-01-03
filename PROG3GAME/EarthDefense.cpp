#include "EarthDefense.h"



EarthDefense::EarthDefense(int x, int y) : GameEngine::FixedSprite(x, y)
{
}

void EarthDefense::createTexture() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
	}
	SDL_Surface* surface = IMG_Load("Sprites/Fixed/ground_defense.png");
	texture = SDL_CreateTextureFromSurface(GameEngine::system.getRenderer(), surface);
	setWH(surface->w, surface->h);
	SDL_FreeSurface(surface);
}

void EarthDefense::draw() const {
	SDL_RenderCopy(GameEngine::system.getRenderer(), texture, NULL, &getRectangle());
}

EarthDefense::~EarthDefense()
{
}
