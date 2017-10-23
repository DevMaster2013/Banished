#pragma once

#include "Framework\GameEntity.h"
#include "Resources\TerrainSpriteSheet.h"
#include "Logic\Map.h"

class MapEntity : public GameEntity
{
private:
	Map* _map;
	TerrainSpriteSheet* _terrainSpriteSheet;
	GameEntity* _tileGameEntity;

public:
	MapEntity();
	MapEntity(GameEntity* parent);
	virtual ~MapEntity();

public:
	void generateMap(MapSettings mapSettings);

protected:
	virtual bool onEntityInit();
	virtual void onEntityRender(sf::RenderWindow* window);
	virtual void onEntityUpdate(sf::RenderWindow* window, float deltaTime);
	virtual void onEntityRelease();
};
