#include <SDL.h>

#include "GameEngine.h"
#include "Life.h"
#define LIVES 3

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


void addLifes() {
	int width = 980;
	int height = 10;

	for (int i = 0; i < LIVES; i++) {
		Life* fs = Life::getInstance(width, height);
		game.addSprite(fs);
		width -= 40;
	}
}

void addEnemies() {

}

void addPlayer() {

}

int main(int argc, char** argv) {

	setUpGame();
	
	addLifes();
	game.gameLoop();

	return 0;
}