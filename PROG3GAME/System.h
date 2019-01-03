#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

/*
*  AUTHOR Tor Olsson/tool2256
*  Represents the window, with the renderer and other general settings  
*/

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
		*  @param font the font to be used
		*/
		void setFont(const TTF_Font& font);

		/*
		*  Loads an image and set it as the background
		*  @param imagePath the path to the image
		*/
		void setBackground(const std::string& imagePath);

		/*
		*  Loads a sound file and sets it as background music
		*  @param musicPath the path to the sound file
		*/
		void setBackgroundMusic(const std::string& musicPath);

		~System();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		TTF_Font* font;
		SDL_Surface* background;
		Mix_Chunk* backgroundMusic;
	};

	extern System system;

}
#endif
