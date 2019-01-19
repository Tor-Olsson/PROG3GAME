#ifndef LIFE_H
#define LIFE_H
#include "FixedSprite.h"

class Life : public GameEngine::FixedSprite
{
public:
	/*
	Creates and returns a new instance of this class, using the static spritePath as picture
	@param x the placement on the screen width
	@param y the placement on the screen height
	*/
	static Life* getInstance(int x, int y);
	~Life();

protected:
	Life(int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
};

#endif