#pragma once

#include "GameEntity.h"

class TestingCircleEntity : public GameEntity
{
public:
	TestingCircleEntity();
	TestingCircleEntity(GameEntity* parent);
	virtual ~TestingCircleEntity();

public:
	virtual bool init() override;
};