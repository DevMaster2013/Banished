#include "Logic\Tile.h"

Tile::Tile()
	: Tile(TileType::NONE)
{
}

Tile::Tile(TileType type)
	: _type(type)
{
}

Tile::~Tile()
{
}

void Tile::setTileType(TileType type)
{
	_type = type;
}

const TileType & Tile::getTileType() const
{
	return _type;
}
