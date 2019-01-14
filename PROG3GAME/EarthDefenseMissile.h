#ifndef EARTHDEFENSEMISSILE_H
#define EARTHDEFENSEMISSILE_H

#include "ComputerControlledSprite.h"

class EarthDefenseMissile : public GameEngine::ComputerControlledSprite
{
public:
	static EarthDefenseMissile* getInstance(int x, int y);
	void tick(const SDL_Event& event);
	~EarthDefenseMissile();

protected:
	EarthDefenseMissile(int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
};

#endif