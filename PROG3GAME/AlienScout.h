#ifndef ALIENSCOUT_H
#define ALIENSCOUT_H

#include <vector>

#include "ComputerControlledSprite.h"
#include "EarthDefenseMissile.h"
#include "GameEngine.h"

class AlienScout : public GameEngine::ComputerControlledSprite
{
public:
	static AlienScout* getInstance(GameEngine::GameEngine& g, int x, int y);
	void tick(const SDL_Event& event);

	~AlienScout();

protected:
	AlienScout(GameEngine::GameEngine& g, int x, int y, const std::string spritePath);

private:
	GameEngine::GameEngine& game;
	static const std::string spritePath;
};

#endif