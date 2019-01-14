#include "AlienScout.h"

#include <iostream> //for test

const std::string AlienScout::spritePath = "Sprites/alien-scout.png";

AlienScout::AlienScout(int x, int y, const std::string spritePath) : ComputerControlledSprite(x, y, spritePath)
{
}

void AlienScout::tick(const SDL_Event& event) {
	int height = getRectangle().y + 1;
	setPosition(getRectangle().x,height);

	/*
	if (AlienScout is out of picture)
	lives -1
	remove AlienScout
	*/
}


AlienScout* AlienScout::getInstance(int x, int y) {
	return new AlienScout(x, y, spritePath);
}


AlienScout::~AlienScout()
{
}
