#include "Life.h"


const std::string Life::spritePath = "Sprites/heart_pixel_art_32x32.png";

Life::Life(int x, int y, const std::string spritePath) : GameEngine::FixedSprite(x,y,spritePath)
{
}

Life* Life::getInstance(int x, int y) {
	return new Life(x, y, spritePath);
}

Life::~Life()
{
}
