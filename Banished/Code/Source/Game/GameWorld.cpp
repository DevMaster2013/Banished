#include "Game\GameWorld.h"
#include "Game\MapEntity.h"

GameWorld::GameWorld()
{
	
}

GameWorld::~GameWorld()
{
	
}

bool GameWorld::onEntityInit()
{	
	auto mapEntity = (MapEntity*)addChild("Map", new MapEntity());
	mapEntity->generateMap({ MapSize::Tiny, "My Map", 100 });

	return true;
}

void GameWorld::onEntityRelease()
{
}

void GameWorld::onEntityRender(sf::RenderWindow * window)
{
}

void GameWorld::onEntityUpdate(sf::RenderWindow * window, float deltaTime)
{
}
