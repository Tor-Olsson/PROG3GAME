#ifndef COMPUTERCONTROLLEDSPRITE_H
#define COMPUTERCONTROLLEDSPRITE_H

#include "MovingSprite.h"

namespace GameEngine {

class ComputerControlledSprite : public MovingSprite
{
public:
	~ComputerControlledSprite();

protected:
	ComputerControlledSprite(int x, int y, const std::string spritePath);
};

}
#endif
