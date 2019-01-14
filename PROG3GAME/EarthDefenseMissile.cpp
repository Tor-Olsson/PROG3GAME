#include "EarthDefenseMissile.h"

#define MISSILESPEED 5

const std::string EarthDefenseMissile::spritePath = "Sprites/ground_defense_projectile.png";

EarthDefenseMissile::EarthDefenseMissile(int x, int y, const std::string spritePath) : GameEngine::ComputerControlledSprite(x, y, spritePath)
{
}

EarthDefenseMissile* EarthDefenseMissile::getInstance(int x, int y) {
	return new EarthDefenseMissile(x, y, spritePath);
}

void EarthDefenseMissile::tick(const SDL_Event& event) {
	int height = getRectangle().y - MISSILESPEED;
	setPosition(getRectangle().x, height);
}


EarthDefenseMissile::~EarthDefenseMissile()
{
}
