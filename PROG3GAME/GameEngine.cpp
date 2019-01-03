#include "GameEngine.h"



namespace GameEngine {

	GameEngine::GameEngine()
	{
	}

	void GameEngine::run() {
		bool run = true; 


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