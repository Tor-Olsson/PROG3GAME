#include "GameEngine.h"

#include <stdexcept>

#include "Sprite.h"
#include "FixedSprite.h"

#include <iostream>//for test, remove

#define FPS 40

namespace GameEngine {

	GameEngine::GameEngine()
	{
	}
	int loopCount = 0;
	void GameEngine::gameLoop() {
		bool run = true; 
		SDL_Event event;

		const int tickIntervall = 1000 / FPS;
		
		while (run) {

			Uint32 nextTick = SDL_GetTicks() + tickIntervall;
			while (SDL_PollEvent(&event)) {

				switch (event.type) {

				case SDL_QUIT:
					run = false;
					break;

				case SDL_KEYDOWN:

					break;

				}// end of switch

			}// end of inner while
			handleSprites();
			for (Sprite * s : sprites) {
				s->tick();
			}
			redraw();
			handleFPS(nextTick - SDL_GetTicks());

		}// end of outer while
	}

	void GameEngine::setFont(const std::string& fontPath, int size) {
		system.setFont(fontPath, size);
	}

	void GameEngine::setTitle(const std::string& title) {
		system.setTitle(title);
	}

	void GameEngine::setBackground(const std::string& imagePath) {
		system.setBackground(imagePath);
	}

	void GameEngine::setBackgroundMusic(const std::string& musicPath) {
		system.setBackgroundMusic(musicPath);
	}

	void GameEngine::addSprite(Sprite* newSprite) {
		std::cout << "adding sprite from Game" << std::endl;
		if (newSprite == NULL) {
			throw std::invalid_argument("addSprite: Null not allowed");
		}

		spritesToAdd.push_back(newSprite);
	}

	bool GameEngine::removeSprite(Sprite* sprite) {
		if (sprites.empty() || sprite == NULL) {
			return false;
		}
		spritesToRemove.push_back(sprite);
		return true;
	}

	void GameEngine::handleSprites() {
		for (Sprite* s : spritesToAdd) {
			std::cout << "adding sprite internal" << std::endl;
			sprites.push_back(s);
		}



		spritesToAdd.clear();
		//REMOVE - Oändlig LOOP
		//for (std::vector<Sprite*>::iterator s = sprites.begin(); s != sprites.end();) {
		//	std::cout << "after for" << std::endl;
		//	for (Sprite * r : spritesToRemove) {
		//		if (*s == r) {
		//			s = sprites.erase(s);
		//			delete r;
		//		}
		//		else {
		//			s++;
		//		}
		//	}
		//}
	}

	void GameEngine::redraw() {
		SDL_RenderClear(system.getRenderer());
		system.drawBackground();
		for (Sprite * s : sprites) {
			std::cout << "draw loop" << std::endl;
				
				s->draw();
		}
		
		SDL_RenderPresent(system.getRenderer());
	}

	void GameEngine::handleFPS(int delay) {

		if (delay > 0) {
			SDL_Delay(delay);
		}
		loopCount++;
	}

	GameEngine::~GameEngine()
	{
		for (Sprite * c : sprites) {
			delete(c);
		}

	}

}