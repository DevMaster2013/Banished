#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <unordered_map>
#include "GameObject.h"

class GameEntity : public GameObject, sf::Transformable
{
protected:
	typedef std::unordered_map<std::string, GameEntity*> ChildList;

protected:
	sf::Texture		_entityTexture;
	sf::Sprite		_entirySprite;

protected:
	GameEntity*		_parentEntity;
	ChildList		_childs;

public:
	GameEntity();
	GameEntity(GameEntity* parent);
	virtual ~GameEntity();

public:
	virtual bool init() override;
	virtual void release() override;
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(sf::RenderWindow* window, float deltaTime) override;

public:
	void addChild(const std::string name, GameEntity* child);

public:
	void setParent(GameEntity* parent);
	void setTexture(const sf::Texture& texture);
	sf::Transform getEntityTransform() const;

protected:
	virtual void onEntityRender(sf::RenderWindow* window);
	virtual void onEntityUpdate(sf::RenderWindow* window, float deltaTime);
};