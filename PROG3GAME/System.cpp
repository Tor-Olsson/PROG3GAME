#include "System.h"

#include <stdexcept>

#include <iostream>//for testing, remove

namespace GameEngine {

	System::System()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
			throw std::runtime_error(SDL_GetError());
		}

		if (TTF_Init() == -1) {
			throw std::runtime_error(TTF_GetError());
		}

		//Sets default font as 'Arial', only on Windows-computers. The font can be changed using setFont();
		font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 36);
		if (font == nullptr) {
			//TODO: 
			//try to fetch linux default font? ...else throw
			throw std::runtime_error(TTF_GetError());
		}
		SDL_Init(SDL_INIT_EVERYTHING);

		window = SDL_CreateWindow("The Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
	}

	SDL_Renderer* System::getRenderer() const{
		return renderer;
	}

	TTF_Font* System::getFont() const {
		return font;
	}

	void System::setFont(const std::string& fontPath, int size) {
		font = TTF_OpenFont(fontPath.c_str(), size);
		if (font == NULL) {
			throw std::invalid_argument(TTF_GetError());
		}
	}

	void System::setBackground(const std::string& imagePath) {
		SDL_Surface* bgSurface = IMG_Load(imagePath.c_str());
		if (bgSurface == NULL) {
			throw std::invalid_argument(IMG_GetError());
		}
		else { //else maybe not needed? Does c++ errors break?
			SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
			SDL_SetWindowSize(window, bgSurface->w, bgSurface->h);
			SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
			SDL_FreeSurface(bgSurface);
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
			SDL_RenderPresent(renderer);
		}
	}

	void System::setBackgroundMusic(const std::string& musicPath) {
		Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
		backgroundMusic = Mix_LoadMUS(musicPath.c_str());
		if (backgroundMusic == NULL) {
			throw std::invalid_argument(Mix_GetError());
		}
		int volume = 80;
		Mix_VolumeMusic(volume);
		Mix_PlayMusic(backgroundMusic, -1);
	}

	void System::setTitle(const std::string& title) {
		SDL_SetWindowTitle(window, title.c_str());
	}


	System::~System()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_CloseFont(font);
		Mix_CloseAudio();
		TTF_Quit();
		SDL_Quit();
	}

	System system;
}
