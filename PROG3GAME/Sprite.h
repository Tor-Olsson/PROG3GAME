#ifndef SPRITE_H
#define SPRITE_H


#include <stdexcept>
#include <vector>

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
		Changes the sprite (image)
		@param spritePath the path to the new image
		@throws invalid_argument if the sprite can't be found
		*/
		void changeSprite(const std::string spritePath);

		/*
		Detects collisions of rectangles belonging to sprites, and saves the other object in *collisioned
		@param sprites the vector with all the sprites to check collisions with
		@return true if a collision was found, otherwise false
		*/
		bool detectCollision(const std::vector<Sprite*> sprites);

		/*
		Returns a pointer to the sprite that this sprite have collisioned with
		@return a pointer to the sprite that this sprite have collided with, otherwise nullptr
		*/
		Sprite* getCollision();

		/*
		Checks if the Sprite is off screen
		@return true if the object is outside the size of the background, otherwise false
		*/
		bool outOfScreen();

		/*
		Handles events in the game loop. Implementation forced to subclasses
		*/
		virtual void tick(const SDL_Event& event) = 0;

		/*
		Keyboard and mouse functions. Implementation should be the game designers decision
		*/
		virtual void mouseDown(const SDL_Event& event) {};
		virtual void mouseUp(const SDL_Event& event) {};
		virtual void keyDown(const SDL_Event& event) {};
		virtual void keyUp(const SDL_Event& event) {};

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
		Changes the position on the screen
		@param x placement on screen width
		@param y placement on screen height
		*/
		void setPosition(int x, int y);

	private:
		SDL_Rect spriteRectangle;
		SDL_Texture* spriteTexture;
		Sprite* collisioned;
		int w;
		int h;
	};
}

#endif