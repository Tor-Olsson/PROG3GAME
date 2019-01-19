#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "System.h"
#include "Sprite.h"

/*
*  AUTHOR Tor Olsson/tool2256
*  Containing the main engine with the sprites
*/


namespace GameEngine {

	class GameEngine
	{
	public:
		GameEngine();
		/*
		*  The main loop
		*/
		void gameLoop();

		/*
		sets the font
		@param fontPath path to the font to be used
		@param size the size of the font
		@throws invalid_argument if the font could not be found
		*/
		void setFont(const std::string& fontPath, int size);

		/*
		*  returns the current font
		*  @return the current font
		*/
		TTF_Font* getFont() const;

		/*
		Sets the title of the window
		@param title the title to be used
		*/
		void setTitle(const std::string& title);

		/*
		Loads an image and set it as the background.
		Adjusts the window size to fit the h/w of the picture and centers the window.
		@param imagePath the path to the image
		@throws invalid_argument if the picture could not be found
		*/
		void setBackground(const std::string& imagePath);

		/*
		Loads a sound file and sets it as background music
		@param musicPath the path to the sound file
		@throws invalid_argument if the sound could not be found
		*/
		void setBackgroundMusic(const std::string& musicPath);

		/*
		Adds a new sprite to the vector
		@param newSprite the sprite to be added
		@throws invalid_argument if newSprite is null
		*/
		void addSprite(Sprite* newSprite);


		/*
		Removes a sprite from the vector
		@param sprite the sprite to be removed
		@returns true if the sprite was removed, else false
		*/
		bool removeSprite(Sprite* sprite);

		~GameEngine();

	private:
		std::vector<Sprite*> sprites;
		std::vector<Sprite*> spritesToAdd;
		std::vector<Sprite*> spritesToRemove;

		/*
		Adds new sprites to the vector and removes the one to be removed
		*/
		void handleSprites();

		/*
		Redraw the sprites and the background
		*/
		void redraw();

		/*
		Handles frames per second to slow down the loop
		@param delay MS the loop should slow down
		*/
		void handleFPS(int delay);
	};

}

#endif

