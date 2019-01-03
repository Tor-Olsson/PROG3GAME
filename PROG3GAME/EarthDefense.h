#ifndef EARTHDEFENSE_H
#define EARTHDEFENSE_H

#include <SDL.h>

#include "FixedSprite.h"
#include "GameEngine.h"

class EarthDefense : public GameEngine::FixedSprite
{
public:
	EarthDefense(int x, int y);
	~EarthDefense();
	void draw() const;
private:
	void createTexture();
	SDL_Texture* texture;
};

#endif