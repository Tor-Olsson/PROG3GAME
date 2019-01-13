#include <SDL.h>

#include "GameEngine.h"


GameEngine::GameEngine game;

/*
*  Help function to make main() easier to read
*  Change this method if your search paths are different
*/
void setUpGame() {
	game.setTitle("Not Space Invaders");
	game.setBackground("Images/Backgrounds/parallax-mountain.jpg");
	game.setBackgroundMusic("Sound/Music/new_hope.mp3");
	game.setFont("Fonts/Unique.ttf", 24);
}

void addSprites() {

}

int main(int argc, char** argv) {

	setUpGame();
	addSprites();
	game.gameLoop();

	return 0;
}