#include "..\Include\TestingCircleEntity.h"

TestingCircleEntity::TestingCircleEntity()
	: GameEntity()
{
}

TestingCircleEntity::TestingCircleEntity(GameEntity * parent)
	: GameEntity(parent)
{
}

TestingCircleEntity::~TestingCircleEntity()
{
}

bool TestingCircleEntity::init()
{
	_entityTexture.loadFromFile("Media\\Textures\\Circle.jpg");

	return GameEntity::init();
}
