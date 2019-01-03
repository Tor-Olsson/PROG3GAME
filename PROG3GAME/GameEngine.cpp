#include "GameEngine.h"



namespace GameEngine {

	GameEngine::GameEngine()
	{
	}

	void GameEngine::run() {
		bool run = true; 


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

	GameEngine::~GameEngine()
	{
	}

}