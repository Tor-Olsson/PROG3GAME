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

		window = SDL_CreateWindow("The Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
	}

	SDL_Renderer* System::getRenderer() const {
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
		SDL_Surface* background = IMG_Load(imagePath.c_str());

		if (background == NULL) {
			throw std::invalid_argument(IMG_GetError());
		}

		w = background->w;
		h = background->h;

		backgroundTexture = SDL_CreateTextureFromSurface(renderer, background);
		SDL_SetWindowSize(window, w, h);
		SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		SDL_FreeSurface(background);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
		SDL_RenderPresent(renderer);

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

	void System::drawBackground() {
		if (backgroundTexture == NULL) {
			throw std::invalid_argument("background not initialized");
		}
		SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	}

	System::~System()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_DestroyTexture(backgroundTexture);
		TTF_CloseFont(font);
		Mix_CloseAudio();
		TTF_Quit();
		SDL_Quit();
	}

	System system;
}
