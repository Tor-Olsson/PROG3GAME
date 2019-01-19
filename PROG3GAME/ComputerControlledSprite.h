#ifndef COMPUTERCONTROLLEDSPRITE_H
#define COMPUTERCONTROLLEDSPRITE_H

#include "MovingSprite.h"

namespace GameEngine {

class ComputerControlledSprite : public MovingSprite
{
public:
	virtual void tick(const SDL_Event& event) = 0;
	virtual ~ComputerControlledSprite();

protected:
	ComputerControlledSprite(int x, int y, const std::string spritePath);
};

}
#endif
