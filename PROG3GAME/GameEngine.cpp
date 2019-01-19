#include "GameEngine.h"

#include <stdexcept>

#include "Sprite.h"
#include "FixedSprite.h"

namespace GameEngine {

	GameEngine::GameEngine()
	{
	}

	void GameEngine::gameLoop(int fps) {
		bool run = true;
		SDL_Event event;
		const int tickIntervall = 1000 / fps;

		while (run) {
			Uint32 nextTick = SDL_GetTicks() + tickIntervall;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					run = false;
				}				
				if (event.type == SDL_KEYDOWN) {
					if (userDefinedFunctions.count(event.key.keysym.sym) > 0)
						userDefinedFunctions[event.key.keysym.sym]();
					for (Sprite * s : sprites) {
						s->keyDown(event);
					}
				}
				if (event.type == SDL_KEYUP) {
					for (Sprite * s : sprites) {
						s->keyUp(event);
					}
				}
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					for (Sprite * s : sprites) {
						s->mouseDown(event);
					}
				}
				if (event.type == SDL_MOUSEBUTTONUP) {
					for (Sprite * s : sprites) {
						s->mouseUp(event);
					}
				}
			}// end of inner while

			handleSprites();

			for (Sprite * s : sprites) {
				s->tick(event);
				s->detectCollision(sprites);
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

	TTF_Font* GameEngine::getFont() const {
		return system.getFont();
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

		for (Sprite * r : spritesToRemove) {
			for (std::vector<Sprite*>::iterator s = sprites.begin(); s != sprites.end();) {
				if (*s == r) {
					s = sprites.erase(s);
					delete r;
				}
				else {
					s++;
				}
			}
		}
		spritesToRemove.clear();
	}

	void GameEngine::redraw() {
		SDL_RenderClear(system.getRenderer());
		system.drawBackground();
		for (Sprite * s : sprites) {
			s->draw();
		}
		SDL_RenderPresent(system.getRenderer());
	}

	void GameEngine::handleFPS(int delay) {
		if (delay > 0) {
			SDL_Delay(delay);
		}
	}

	void GameEngine::addFunction(FunctionPointer func, const char* x) {
		SDL_Keycode keyCode = SDL_GetKeyFromName(x);
		if (keyCode != 0)
			userDefinedFunctions[keyCode] = func;
	}

	GameEngine::~GameEngine()
	{
		for (Sprite * c : sprites) {
			delete(c);
		}
	}
}