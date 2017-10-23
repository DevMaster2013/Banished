#include "Framework\GameEntity.h"

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
	if (!onEntityInit())
		return false;

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

	onEntityRelease();
}

void GameEntity::render(sf::RenderWindow * window)
{
	onEntityRender(window);

	// Render the entity
	if (_entityTexture != nullptr)
	{
		_entirySprite.setTexture(*_entityTexture);

		if (_textureRect.width >= 0 && _textureRect.height >= 0)
			_entirySprite.setTextureRect(_textureRect);
	}
	window->draw(_entirySprite, getEntityTransform());

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

GameEntity* GameEntity::addChild(const std::string name, GameEntity * child)
{
	if (_childs.find(name) == _childs.end())
	{
		child->setParent(this);
		_childs[name] = child;
	}
	return _childs[name];
}

void GameEntity::setParent(GameEntity * parent)
{
	_parentEntity = parent;
}

void GameEntity::setTexture(sf::Texture* texture)
{
	_entityTexture = texture;
}

void GameEntity::setTextureRect(sf::IntRect textureRect)
{
	_textureRect = textureRect;
}

sf::Transform GameEntity::getEntityTransform() const
{
	if (_parentEntity == nullptr)
		return getTransform();
	return _parentEntity->getEntityTransform() * getTransform();
}

bool GameEntity::onEntityInit()
{
	return true;
}

void GameEntity::onEntityRender(sf::RenderWindow * window)
{
}

void GameEntity::onEntityUpdate(sf::RenderWindow * window, float deltaTime)
{
}

void GameEntity::onEntityRelease()
{
}
