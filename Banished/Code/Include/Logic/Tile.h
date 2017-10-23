#pragma once

enum class TileType
{
	NONE,
	GROUND,
	GRASS,
	SAND,
	MOUNTAIN,
	FOREST,
	ROCKS,
	SEA,
	RIVER,
	LAKE,
	TileTypeCount
};

class Tile
{
private:
	TileType _type;

public:
	Tile();
	Tile(TileType type);
	~Tile();

public:
	void setTileType(TileType type);
	const TileType& getTileType() const;
};