#include "Game\MapEntity.h"
#include "Resources\GameResources.h"
#include "Game\GameConstants.h"

MapEntity::MapEntity()
	: _map(nullptr)
	, _terrainSpriteSheet(nullptr)
{	
}

MapEntity::MapEntity(GameEntity * parent)
	: _map(nullptr)
	, _terrainSpriteSheet(nullptr)
{
}

MapEntity::~MapEntity()
{
}

void MapEntity::generateMap(MapSettings mapSettings)
{
	if (_map != nullptr)
		delete _map;

	_map = new Map(mapSettings);	
}

bool MapEntity::onEntityInit()
{
	// Load the terrain sprite sheet
	_terrainSpriteSheet = (TerrainSpriteSheet*)GameResources::getSpriteSheetResourceManager()->getResource("Terrain_01");
	if (_terrainSpriteSheet == nullptr)
		return false;

	// Initilaize the game tile entity
	_tileGameEntity = addChild("TileEntity", new GameEntity());
	_tileGameEntity->setTexture(_terrainSpriteSheet->getTexture());

	return true;
}

void MapEntity::onEntityRender(sf::RenderWindow * window)
{
	_tileGameEntity->setTextureRect(_terrainSpriteSheet->getRegion("Ground", 3, 3));

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			_tileGameEntity->setPosition(i * TILE_SIZE_X, j * TILE_SIZE_Y);
			_tileGameEntity->render(window);
		}
	}	
}

void MapEntity::onEntityUpdate(sf::RenderWindow * window, float deltaTime)
{
}

void MapEntity::onEntityRelease()
{	
	if (_map != nullptr)
		delete _map;	
}
