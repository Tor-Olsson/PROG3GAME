#include <SDL.h>

#include "GameEngine.h"
#include "Sprite.h"
#include "FixedSprite.h"
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

void addSprites() {
	//for int i = 0; i<lives;i++
	//add new LifeSprite
}

int main(int argc, char** argv) {

	setUpGame();
	GameEngine::FixedSprite* fs = GameEngine::FixedSprite::getInstance(250, 0, "Sprites/alien-scout.png");
	game.addSprite(fs);
	addSprites();
	game.gameLoop();

	return 0;
}