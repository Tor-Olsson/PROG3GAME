#ifndef ALIENSCOUT_H
#define ALIENSCOUT_H

#include <vector>

#include "ComputerControlledSprite.h"

class AlienScout : public GameEngine::ComputerControlledSprite
{
public:
	static AlienScout* getInstance(int x, int y);
	void tick(const SDL_Event& event);

	~AlienScout();

protected:
	AlienScout(int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
};

#endif