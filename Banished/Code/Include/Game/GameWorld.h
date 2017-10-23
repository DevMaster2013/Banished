#pragma once

#include <string>
#include <unordered_map>
#include "Framework\GameObject.h"
#include "Framework\GameEntity.h"

class GameWorld : public GameEntity
{
public:
	GameWorld();
	virtual ~GameWorld();

protected:
	virtual bool onEntityInit() override;
	virtual void onEntityRelease() override;
	virtual void onEntityRender(sf::RenderWindow* window);
	virtual void onEntityUpdate(sf::RenderWindow* window, float deltaTime);
};