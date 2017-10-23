#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <unordered_map>

class SpriteSheet
{
protected:
	typedef std::unordered_map<std::string, sf::IntRect> RegionList;

protected:	
	sf::Texture* _sheetTexture;
	RegionList	_regions;

public:
	SpriteSheet();
	SpriteSheet(sf::Texture* texture);
	virtual ~SpriteSheet();

public:
	void prepare();
	sf::IntRect getRegion(const std::string& regionName);
	sf::IntRect getRegion(const std::string& regionName, int offsetX, int offsetY);

public:
	sf::Texture* getTexture() const;

protected:
	virtual void defineRegions() = 0;
};