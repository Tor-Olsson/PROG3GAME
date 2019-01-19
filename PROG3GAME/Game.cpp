#include <SDL.h>

#include <iostream> //test
#include <ctime> //for random

#include "GameEngine.h"
#include "Life.h"
#include "AlienScout.h"
#include "EarthDefense.h"
#include "EarthDefenseMissile.h"

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


void addEnemies() {
	int random = std::rand() % 700;
	AlienScout* ccs = AlienScout::getInstance(game, random, 0);
	game.addSprite(ccs);
}

void addPlayer() {
	Life* fs = Life::getInstance(980, 10);
	game.addSprite(fs);
	EarthDefense* player = EarthDefense::getInstance(game, 480, 480);
	game.addSprite(player);
}


int main(int argc, char** argv) {
	
	setUpGame();
	addPlayer();
	addEnemies();

	game.gameLoop();
	return 0;
}