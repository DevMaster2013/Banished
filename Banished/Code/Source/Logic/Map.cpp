#include "Logic\Map.h"

Map::Map()
	: Map({MapSize::Tiny, "Default Map", 0})
{
}

Map::Map(MapSettings mapSettings)
	: _mapSettings(mapSettings)

{
	initializeTiles();
}

Map::~Map()
{
	for (size_t i = 0; i < (size_t)_mapSettings.mapSize; i++)
	{
		for (size_t j = 0; j < (size_t)_mapSettings.mapSize; j++)
			delete _mapTiles[i][j];
		delete[] _mapTiles[i];
	}
	delete[] _mapTiles;
}

Tile * Map::getTile(size_t x, size_t y)
{
	if (x >= (size_t)_mapSettings.mapSize || y >= (size_t)_mapSettings.mapSize)
		return nullptr;
	return _mapTiles[y][x];
}

MapSettings Map::getMapSettings() const
{
	return _mapSettings;
}

void Map::initializeTiles()
{
	// Allocate memory for map tiles and set default values
	_mapTiles = new Tile**[(size_t)_mapSettings.mapSize];
	for (size_t i = 0; i < (size_t)_mapSettings.mapSize; i++)
	{
		_mapTiles[i] = new Tile*[(size_t)_mapSettings.mapSize];
		for (size_t j = 0; j < (size_t)_mapSettings.mapSize; j++)
		{
			_mapTiles[i][j] = new Tile(TileType::GROUND);			
		}
	}
}
