#ifndef EARTHDEFENSE_H
#define EARTHDEFENSE_H

#include "PlayerControlledSprite.h"

class EarthDefense : public GameEngine::PlayerControlledSprite
{
public:
	static EarthDefense* getInstance(int x, int y);
	~EarthDefense();

protected:
	EarthDefense(int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
};

#endif