#ifndef EARTHDEFENSEMISSILE_H
#define EARTHDEFENSEMISSILE_H

#include "ComputerControlledSprite.h"
#include "GameEngine.h"
#include <iostream>

class EarthDefenseMissile : public GameEngine::ComputerControlledSprite
{
public:
	static EarthDefenseMissile* getInstance(GameEngine::GameEngine& g, int x, int y);
	void tick(const SDL_Event& event);
	~EarthDefenseMissile();

protected:
	EarthDefenseMissile(GameEngine::GameEngine& g, int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
	GameEngine::GameEngine& game;
};

#endif