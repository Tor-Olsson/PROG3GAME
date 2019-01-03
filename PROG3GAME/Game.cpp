#include <SDL.h>

#include "GameEngine.h"

GameEngine::GameEngine game;

/*
*  Help function to make main() easier to read
*/
void setUpGame() {
	game.setTitle("Spelet");
	game.setBackground("Images/Backgrounds/parallax-mountain.jpg");
	game.setBackgroundMusic("Sound/Music/new_hope_ext.mp3");
}

int main(int argc, char** argv) {

	setUpGame();
	game.run();

	SDL_Delay(3000);

	return 0;
}