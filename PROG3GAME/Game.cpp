#include <iostream>

#include <SDL.h>

#include "GameEngine.h"
#include "Life.h"
#include "AlienScout.h"
#include "EarthDefense.h"
#include "EarthDefenseMissile.h"

GameEngine::GameEngine game;

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

void skriv() {
	std::cout << "User defined function \n";
}

int main(int argc, char** argv) {
	//Setup
	setUpGame();
	//Sprites
	addPlayer();
	addEnemies();
	//User defined function
	void(*fpek)() = skriv;
	game.addFunction(fpek, "A");
	//Run
	game.gameLoop(50);
	return 0;
}