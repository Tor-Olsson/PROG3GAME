#include "EarthDefense.h"

//Increase SPEED if you want to move faster :)
#define SPEED 5

const std::string EarthDefense::spritePath = "Sprites/ground_defense.png";

EarthDefense::EarthDefense(int x, int y, const std::string spritePath) : PlayerControlledSprite(x, y, spritePath)
{
}

EarthDefense* EarthDefense::getInstance(int x, int y) {
	return new EarthDefense(x, y, spritePath);
}

void EarthDefense::tick(const SDL_Event& event) {
	switch (event.type) {

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_RIGHT: {
			int xPos = getRectangle().x + SPEED;
			setPosition(xPos, getRectangle().y);
			break;
		}
		case SDLK_LEFT: {
			int xPos = getRectangle().x - SPEED;
			setPosition(xPos, getRectangle().y);
			break;
		}
		case SDLK_SPACE: {
			//add a new sprite to the gameengine
			//GameEngine.setTitle("hej");
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
