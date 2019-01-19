#include "EarthDefense.h"


//Increase SPEED if you want to move faster :)
#define SPEED 10
#define RELOADTIME 25
#define SPAWNTIME 100

const std::string EarthDefense::spritePath = "Sprites/ground_defense_inverted.png";

EarthDefense::EarthDefense(GameEngine::GameEngine& g, int x, int y, const std::string spritePath) : PlayerControlledSprite(x, y, spritePath), game(g)
{

}

EarthDefense* EarthDefense::getInstance(GameEngine::GameEngine& g, int x, int y) {

	return new EarthDefense(g, x, y, spritePath);
}

void EarthDefense::tick(const SDL_Event& event) {

	if (getCollision() != nullptr && typeid(*getCollision()) == typeid(AlienScout)) {
		game.removeSprite(getCollision());
		game.removeSprite(this);
	}

	//Add new enemies. Probably not the most logical place to do it...
	if (spawnTime == SPAWNTIME) {
		int random = std::rand() % 700;

		game.addSprite(AlienScout::getInstance(game, random + 50, 0));
		spawnTime = 0;
	}
	else
		spawnTime++;

	//delay on shots
	if (reloading) {
		if (reloadTime == RELOADTIME) {
			reloading = false;
		}
		else {
			reloadTime++;
		}
	}

}

void EarthDefense::keyDown(const SDL_Event& event) {
	switch (event.key.keysym.sym) {
	case SDLK_RIGHT: {
		changeSprite("Sprites/ground_defense_inverted.png");
		int xPos = getRectangle().x + SPEED;
		setPosition(xPos, getRectangle().y);
		break;
	}
	case SDLK_LEFT: {
		changeSprite("Sprites/ground_defense.png");
		int xPos = getRectangle().x - SPEED;
		setPosition(xPos, getRectangle().y);
		break;
	}
	case SDLK_UP: {
		if (!reloading && !outOfScreen()) {
			reloading = true;
			reloadTime = 0;
			game.addSprite(EarthDefenseMissile::getInstance(game, getRectangle().x, getRectangle().y));
		}
		break;
	}
	}
}

EarthDefense::~EarthDefense()
{
}
