#ifndef EARTHDEFENSE_H
#define EARTHDEFENSE_H

#include "PlayerControlledSprite.h"
#include "GameEngine.h"

class EarthDefense : public GameEngine::PlayerControlledSprite
{
public:
	static EarthDefense* getInstance(int x, int y);
	void tick(const SDL_Event& event) override;
	void keyDown(const SDL_Event& event) override;
	void keyUp(const SDL_Event& event) override;
	~EarthDefense();

protected:
	EarthDefense(int x, int y, const std::string spritePath);

private:
	static const std::string spritePath;
};

#endif