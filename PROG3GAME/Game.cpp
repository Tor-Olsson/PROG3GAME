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
	//height = 0;
	//width = random
	//??randomisera spawning time? görs det i loopen eller i spelet?
	//c++ "random" does not seem to be so random
	std::srand(std::time(nullptr));
	int random = std::rand() % 700;
	AlienScout* ccs = AlienScout::getInstance(game, random, 0);
	game.addSprite(ccs);
}

void addPlayer() {
	EarthDefense* player = EarthDefense::getInstance(game, 480, 480);
	game.addSprite(player);

}


int main(int argc, char** argv) {

	setUpGame();
	addLifes();
	addPlayer();
	addEnemies();

	game.gameLoop();
	return 0;
}