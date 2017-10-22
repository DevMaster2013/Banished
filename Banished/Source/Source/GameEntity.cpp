#include "..\Include\GameEntity.h"

GameEntity::GameEntity()
	 : _parentEntity(nullptr)
{
}

GameEntity::GameEntity(GameEntity * parent)
	: _parentEntity(parent)

{
}

GameEntity::~GameEntity()
{
	
}

bool GameEntity::init()
{
	for each (auto& child in _childs)
		if (!child.second->init())
			return false;

	return true;
}

void GameEntity::release()
{
	for each (auto& child in _childs)
		delete child.second;
	_childs.clear();
}

void GameEntity::render(sf::RenderWindow * window)
{
	onEntityRender(window);

	// Render the childs
	for each (auto& child in _childs)
		child.second->render(window);
}

void GameEntity::update(sf::RenderWindow * window, float deltaTime)
{
	onEntityUpdate(window, deltaTime);

	// Render the childs
	for each (auto& child in _childs)
		child.second->update(window, deltaTime);
}

void GameEntity::addChild(const std::string name, GameEntity * child)
{
	if (_childs.find(name) == _childs.end())
	{
		child->setParent(this);
		_childs[name] = child;
	}
}

void GameEntity::setParent(GameEntity * parent)
{
	_parentEntity = parent;
}

void GameEntity::setTexture(const sf::Texture & texture)
{
	_entityTexture = texture;
}

sf::Transform GameEntity::getEntityTransform() const
{
	return _parentEntity->getTransform() * getTransform();
}

void GameEntity::onEntityRender(sf::RenderWindow * window)
{
	// Render the entity
	_entirySprite.setTexture(_entityTexture);
	window->draw(_entirySprite, getEntityTransform());
}

void GameEntity::onEntityUpdate(sf::RenderWindow * window, float deltaTime)
{
}
