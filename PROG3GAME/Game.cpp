#include <SDL.h>

#include "GameEngine.h"

int main(int argc, char** argv) {

	GameEngine::GameEngine game;
	game.setTitle("Spelet");
	game.setBackground("parallax-mountain.jpg");
	game.setBackgroundMusic("new_hope_ext.mp3");
	game.run();

	SDL_Delay(3000);

	return 0;
}