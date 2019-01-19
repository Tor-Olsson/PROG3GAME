#ifndef EARTHDEFENSEMISSILE_H
#define EARTHDEFENSEMISSILE_H

#include "ComputerControlledSprite.h"
#include "GameEngine.h"

class EarthDefenseMissile : public GameEngine::ComputerControlledSprite
{
public:
	static EarthDefenseMissile* getInstance(GameEngine::GameEngine& g, int x, int y);
	void tick(const SDL_Event& event);

protected:
	EarthDefenseMissile(GameEngine::GameEngine& g, int x, int y, const std::string spritePath);

private:
	~EarthDefenseMissile();
	static const std::string spritePath;
	GameEngine::GameEngine& game;
	int tickCount;
};

#endif