#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

class Game
{
private:
	sf::RenderWindow*	_renderWindow;
	sf::View			_cameraView;
	sf::Thread*			_renderThread;
	sf::CircleShape		_playerShip;

public:
	Game();
	~Game();

public:
	void run();

private:
	void update();
	void render();
};