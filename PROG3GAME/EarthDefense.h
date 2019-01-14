#ifndef EARTHDEFENSE_H
#define EARTHDEFENSE_H

#include "PlayerControlledSprite.h"
#include "EarthDefenseMissile.h"
#include "GameEngine.h"

class EarthDefense : public GameEngine::PlayerControlledSprite
{
public:
	static EarthDefense* getInstance(GameEngine::GameEngine& g, int x, int y);
	void tick(const SDL_Event& event) override;
	void keyDown(const SDL_Event& event) override;
	void keyUp(const SDL_Event& event) override;
	~EarthDefense();

protected:
	EarthDefense(GameEngine::GameEngine& g, int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
	GameEngine::GameEngine& game;
	bool reloading = false;
	int reloadTime = 0;
};

#endif