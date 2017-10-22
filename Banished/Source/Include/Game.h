#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Camera.h"

class Game
{
private:
	sf::RenderWindow*	_renderWindow;	
	sf::Thread*			_renderThread;
	sf::Thread*			_updateThread;
	sf::CircleShape		_playerShip;

	Camera				_cameraView;

public:
	Game();
	~Game();

public:
	void run();

private:
	void handleEvents();
	void update();
	void render();
};