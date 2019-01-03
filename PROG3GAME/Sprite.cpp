#include "Sprite.h"

namespace GameEngine {

	Sprite::Sprite(int x, int y, int w, int h) : rect {x, y, w, h}
	{
	}

	SDL_Rect Sprite::getRectangle() const{
		return rect;
	}

	void Sprite::setWH(int w, int h) {
		rect.w = w;
		rect.h = h;
	}

}
