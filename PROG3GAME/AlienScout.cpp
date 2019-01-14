#include "AlienScout.h"

#include <iostream> //for test

const std::string AlienScout::spritePath = "Sprites/alien-scout.png";

AlienScout::AlienScout(GameEngine::GameEngine& g, int x, int y, const std::string spritePath) : ComputerControlledSprite(x, y, spritePath), game(g)
{
}

void AlienScout::tick(const SDL_Event& event) {
	int height = getRectangle().y + 1;
	setPosition(getRectangle().x,height);

	if (getCollision()) {
		game.removeSprite(this);
	}

	/*
	if (AlienScout is out of picture)
	lives -1
	remove AlienScout
	*/
}


AlienScout* AlienScout::getInstance(GameEngine::GameEngine& g, int x, int y) {
	return new AlienScout(g, x, y, spritePath);
}


AlienScout::~AlienScout()
{
}
