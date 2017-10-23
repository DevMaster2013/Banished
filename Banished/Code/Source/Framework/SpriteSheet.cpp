#include "Framework\SpriteSheet.h"
#include "Game\GameConstants.h"
#include "Game\GameUtilities.h"

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::SpriteSheet(sf::Texture* texture)
	: _sheetTexture(texture)
{
}

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::prepare()
{
	// Define the texture regions
	defineRegions();
}

sf::IntRect SpriteSheet::getRegion(const std::string & regionName)
{
	if (_regions.find(regionName) != _regions.end())
		return _regions[regionName];
	return sf::IntRect();
}

sf::IntRect SpriteSheet::getRegion(const std::string & regionName, int offsetX, int offsetY)
{
	sf::IntRect entire = getRegion(regionName);
	if (entire.width == 0) return entire;
	entire.left		= min(max(entire.left + offsetX * TILE_SIZE_X, 0), _sheetTexture->getSize().x - TILE_SIZE_X - 1);
	entire.top		= min(max(entire.top + offsetY * TILE_SIZE_Y, 0), _sheetTexture->getSize().y - TILE_SIZE_Y - 1);
	entire.width	= TILE_SIZE_X;
	entire.height	= TILE_SIZE_Y;
	return entire;
}

sf::Texture * SpriteSheet::getTexture() const
{
	return _sheetTexture;
}
