#include "..\Include\Game.h"

Game::Game()
	: _renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "Banished"))
	, _cameraView(800.0f, 600.0f)
	, _renderThread(nullptr)
	, _updateThread(nullptr)
	, _playerShip(sf::CircleShape(50.0f))
{	
	_playerShip.setFillColor(sf::Color::Green);
}

Game::~Game()
{
	delete _renderWindow;
}

void Game::run()
{
	// DeActivate the window
	_renderWindow->setActive(false);

	// Creating rendering thread
	_renderThread = new sf::Thread(&Game::render, this);
	_updateThread = new sf::Thread(&Game::update, this);
	_renderThread->launch();
	_updateThread->launch();

	// calling the update function
	handleEvents();
}

void Game::handleEvents()
{
	// the rendering loop
	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			// catch the close events
			if (event.type == sf::Event::Closed)
				_renderWindow->close();			

			// handle the event in the camera objects
			_cameraView.onEvent(event);
		}
	}
}

void Game::update()
{
	sf::Clock updateClock;

	// the rendering loop
	while (_renderWindow->isOpen())
	{		
		float elapsedTime = updateClock.restart().asSeconds();
		_cameraView.update(_renderWindow, elapsedTime);
	}
}

void Game::render()
{
	// Activate the window
	_renderWindow->setActive(true);

	// the rendering loop
	while (_renderWindow->isOpen())
	{
		// draw the stuff
		_renderWindow->setView(_cameraView.getView());
		_renderWindow->clear();
		_renderWindow->draw(_playerShip);
		_renderWindow->display();
	}
}
