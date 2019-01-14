#ifndef SPRITE_H
#define SPRITE_H


#include <stdexcept>

#include <SDL.h>
#include "System.h"

namespace GameEngine {
	class Sprite
	{
	public:
		/*
		Forbids copying of objects
		*/
		Sprite(const Sprite&) = delete;

		/*
		Forbids allocation through = operator
		*/
		const Sprite& operator = (const Sprite&) = delete;

		/*
		returns the rectangle
		@return the rectangle
		*/
		SDL_Rect getRectangle() const;

		/*
		Redraws the texture
		Implemented in superclass because all sprites have a picture that needs to be redrawn
		*/
		void draw() const;
			   
		/*
		Handles events in the game loop. Implementation forced to subclasses
		*/
		virtual void tick(const SDL_Event& event) = 0;

		virtual ~Sprite() { SDL_DestroyTexture(spriteTexture); };
	protected:
		/*
		Constructor
		@param x the placement on the screen width
		@param y placement on the screen height
		@param spritePath path to the picture to be used
		@throws invalid_argument if the sprite can't be found
		*/
		Sprite(int x, int y, const std::string spritePath);
		
		/*
		Sets the width and height of the triangle
		@param w the width
		@param h the height
		POSSIBLY UNUSED
		*/
		void setWH(int w, int h);

		/*
		Changes the position on the screen
		@param x placement on screen width
		@param y placement on screen height
		*/
		void setPosition(int x, int y);

	private:
		SDL_Rect spriteRectangle;
		SDL_Texture* spriteTexture;
	};
}

#endif