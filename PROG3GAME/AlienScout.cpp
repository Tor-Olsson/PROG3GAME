#include "AlienScout.h"

const std::string AlienScout::spritePath = "Sprites/alien-scout.png";

AlienScout::AlienScout(GameEngine::GameEngine& g, int x, int y, const std::string spritePath) : ComputerControlledSprite(x, y, spritePath), game(g)
{
}

void AlienScout::tick(const SDL_Event& event) {
	int height = getRectangle().y + 1;
	setPosition(getRectangle().x, height);

	if (getCollision() != nullptr && typeid(*getCollision()) == typeid(EarthDefenseMissile)) {
		game.removeSprite(getCollision());
		game.removeSprite(this);
	}

	if (outOfScreen()) {
		game.removeSprite(this);
	}
}


AlienScout* AlienScout::getInstance(GameEngine::GameEngine& g, int x, int y) {
	return new AlienScout(g, x, y, spritePath);
}


AlienScout::~AlienScout()
{

}
