#include "EarthDefense.h"


const std::string EarthDefense::spritePath = "Sprites/ground_defense.png";

EarthDefense::EarthDefense(int x, int y, const std::string spritePath) : PlayerControlledSprite(x,y,spritePath)
{
}

EarthDefense* EarthDefense::getInstance(int x, int y) {
	return new EarthDefense(x, y, spritePath);
}

EarthDefense::~EarthDefense()
{
}
