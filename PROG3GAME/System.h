#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

namespace GameEngine {

	class System
	{

	public:
		System();

		/*
		*  Returns the renderer
		*  @return the renderer
		*/
		SDL_Renderer* getRenderer() const;

		/*
		*  returns the current font
		*  @return the current font
		*/
		TTF_Font* getFont() const;

		/*
		*  sets the font
		*  @param fontPath path to the font to be used
		*  @param size the size of the font
		*  @throws invalid_argument if the font could not be found
		*/
		void setFont(const std::string& fontPath, int size);

		/*
		*  Loads an image and set it as the background. 
		*  Adjusts the window size to fit the h/w of the picture, and centers the window.
		*  @param imagePath the path to the image
		*  @throws invalid_argument if the picture could not be found
		*/
		void setBackground(const std::string& imagePath);

		/*
		*  Loads a sound file and sets it as background music
		*  @param musicPath the path to the sound file
		*  @throws invalid_argument if the sound could not be found
		*/
		void setBackgroundMusic(const std::string& musicPath);

		/*
		*  Sets the title of the window
		*  @param title the title to be used
		*/
		void setTitle(const std::string& title);

		/*
		*  Redraws the background, used for the game loop
		*  @throw invalid_argument if the backgroundTexture is null
		*/
		void drawBackground();

		/*
		@return the width of the window
		*/
		int getWidth() { return w; }

		/*
		@return the height of the window
		*/
		int getHeight() { return h; }

		~System();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		TTF_Font* font;
		SDL_Texture* backgroundTexture;
		Mix_Music* backgroundMusic;
		int w;
		int h;
	};

	extern System system;

}
#endif
