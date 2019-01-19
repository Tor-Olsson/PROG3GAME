#include "EarthDefenseMissile.h"

#define MISSILESPEED 5

const std::string EarthDefenseMissile::spritePath = "Sprites/ground_defense_projectile_1.png";

EarthDefenseMissile::EarthDefenseMissile(GameEngine::GameEngine& g, int x, int y, const std::string spritePath) : GameEngine::ComputerControlledSprite(x, y, spritePath), game(g)
{
}

EarthDefenseMissile* EarthDefenseMissile::getInstance(GameEngine::GameEngine& g, int x, int y) {
	return new EarthDefenseMissile(g, x, y, spritePath);
}

void EarthDefenseMissile::tick(const SDL_Event& event) {
	if (outOfScreen()) {
		game.removeSprite(this);
	}
	int height = getRectangle().y - MISSILESPEED;
	setPosition(getRectangle().x, height);
	//"Animation"
	tickCount++;
	if (tickCount == 20) {
		changeSprite("Sprites/ground_defense_projectile_2.png");
	}
	if (tickCount == 40) {
		changeSprite("Sprites/ground_defense_projectile_3.png");
	}
}


EarthDefenseMissile::~EarthDefenseMissile()
{

}
