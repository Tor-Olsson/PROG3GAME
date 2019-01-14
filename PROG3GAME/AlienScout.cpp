#include "AlienScout.h"

const std::string AlienScout::spritePath = "Sprites/alien-scout.png";

AlienScout::AlienScout(int x, int y, const std::string spritePath) : ComputerControlledSprite(x,y,spritePath)
{
}

AlienScout* AlienScout::getInstance(int x, int y) {
	return new AlienScout(x, y, spritePath);
}


AlienScout::~AlienScout()
{
}
