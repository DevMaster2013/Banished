#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <unordered_map>
#include <string>
#include "Framework\GameObject.h"

class Game
{
private:
	typedef std::unordered_map<std::string, GameObject*> GameObjectList;

private:
	sf::RenderWindow*	_renderWindow;	
	sf::Thread*			_renderThread;
	sf::Thread*			_updateThread;
	GameObjectList		_gameObjects;

public:
	Game();
	~Game();

public:
	bool init();
	void run();
	void release();

private:
	void handleEvents();
	void update();
	void render();
};