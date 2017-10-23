#pragma once

#include <string>
#include "Logic\Tile.h"

enum class MapSize : size_t
{
	Tiny = 64,
	Small = 128,
	Medium = 256,
	Large = 512,
	Huge = 1024,
	MapSizeCount
};

struct MapSettings
{
public:
	MapSize			mapSize;
	std::string		mapName;
	unsigned int	randomSeed;
};

class Map
{
private:
	MapSettings		_mapSettings;
	Tile***			_mapTiles;
	
public:
	Map();
	Map(MapSettings mapSettings);
	~Map();

public:
	Tile* getTile(size_t x, size_t y);	
	MapSettings getMapSettings() const;

private:
	void initializeTiles();
};