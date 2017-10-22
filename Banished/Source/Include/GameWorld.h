#pragma once

#include <string>
#include <unordered_map>
#include "GameObject.h"
#include "GameEntity.h"

class GameWorld : public GameEntity
{
public:
	GameWorld();
	virtual ~GameWorld();

public:
	virtual bool init() override;
	virtual void release() override;

protected:
	virtual void onEntityRender(sf::RenderWindow* window);
	virtual void onEntityUpdate(sf::RenderWindow* window, float deltaTime);
};