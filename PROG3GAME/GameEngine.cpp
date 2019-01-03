#include "GameEngine.h"

#include <stdexcept>

#include <iostream>//for test, remove

namespace GameEngine {

	GameEngine::GameEngine()
	{
	}

	void GameEngine::gameLoop() {
		bool run = true; 
		SDL_Event event;

		while (run) {
			while (SDL_PollEvent(&event)) {

				switch (event.type) {

				case SDL_QUIT:
					run = false;
					break;

				case SDL_KEYDOWN:
					for (Sprite * s : sprites) {
						//s->tick(event);
					}
					break;

				}// end of switch

			}// end of inner while

			handleSprites();
			redraw();
			
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
			sprites.push_back(s);
		}
		spritesToAdd.clear();

		for (std::vector<Sprite*>::iterator s = sprites.begin(); s != sprites.end();) {
			for (Sprite * r : spritesToRemove) {
				if (*s == r) {
					s = sprites.erase(s);
					delete r;
				}
				else {
					s++;
				}
			}
		}
	}

	void GameEngine::redraw() {
		SDL_RenderClear(system.getRenderer());
		system.drawBackground();
		for (Sprite * s : sprites) {
			//	s->draw();
		}
		SDL_RenderPresent(system.getRenderer());
	}

	GameEngine::~GameEngine()
	{
		for (Sprite * c : sprites) {
			delete(c);
		}

	}

}