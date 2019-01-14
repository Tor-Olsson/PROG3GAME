#include "EarthDefense.h"

#include <iostream> //test

//Increase SPEED if you want to move faster :)
#define SPEED 5
#define RELOADTIME 25

const std::string EarthDefense::spritePath = "Sprites/ground_defense.png";

EarthDefense::EarthDefense(GameEngine::GameEngine& g, int x, int y, const std::string spritePath) : PlayerControlledSprite(x, y, spritePath), game(g)
{

}

EarthDefense* EarthDefense::getInstance(GameEngine::GameEngine& g, int x, int y) {
	return new EarthDefense(g, x, y, spritePath);
}

void EarthDefense::tick(const SDL_Event& event) {



	//delay on shots
	if (reloading) {
		if (reloadTime == RELOADTIME) {
			reloading = false;
		}
		else {
			reloadTime++;
		}
	}

	switch (event.type) {

	case SDL_KEYDOWN:
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
			if (!reloading) {
				reloading = true;
				reloadTime = 0;
				EarthDefenseMissile* missile = EarthDefenseMissile::getInstance(getRectangle().x, getRectangle().y);
				game.addSprite(missile);
			}
			break;
		}
		}
	}
}

	void EarthDefense::keyDown(const SDL_Event& event) {

	}

	void EarthDefense::keyUp(const SDL_Event& event) {

	}

	EarthDefense::~EarthDefense()
	{
	}
