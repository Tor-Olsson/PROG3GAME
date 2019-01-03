#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL.h>

#include "System.h"

namespace GameEngine {

	class GameEngine
	{
	public:
		GameEngine();
		void run();
		void setTitle(const std::string& title);
		void setBackground(const std::string& imagePath);
		void setBackgroundMusic(const std::string& musicPath);
		~GameEngine();
	};

}

#endif

