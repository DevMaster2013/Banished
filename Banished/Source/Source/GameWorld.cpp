#include "..\Include\GameWorld.h"
#include "..\Include\TestingCircleEntity.h"

GameWorld::GameWorld()
{
}

GameWorld::~GameWorld()
{
	
}

bool GameWorld::init()
{
	addChild("Testing", new TestingCircleEntity());
	return GameEntity::init();
}

void GameWorld::release()
{
}

void GameWorld::onEntityRender(sf::RenderWindow * window)
{
}

void GameWorld::onEntityUpdate(sf::RenderWindow * window, float deltaTime)
{
}
