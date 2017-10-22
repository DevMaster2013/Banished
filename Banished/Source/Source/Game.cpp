#include "..\Include\Game.h"

Game::Game()
	: _renderWindow(new sf::RenderWindow(sf::VideoMode(800, 600), "Banished"))
	, _cameraView(_renderWindow->getView())
	, _renderThread(nullptr)
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
	_renderThread->launch();

	// calling the update function
	update();
}

void Game::update()
{
	// update the view
	_cameraView.setCenter(0, 0);

	// the rendering loop
	while (_renderWindow->isOpen())
	{
		sf::Event event;
		while (_renderWindow->pollEvent(event))
		{
			// catch the close events
			if (event.type == sf::Event::Closed)
				_renderWindow->close();

			// catch the resize events
			if (event.type == sf::Event::Resized)
				_cameraView.setSize(event.size.width, event.size.height);
		}
	}
}

void Game::render()
{
	// Activate the window
	_renderWindow->setActive(true);

	// the rendering loop
	while (_renderWindow->isOpen())
	{
		// set the camera view
		_renderWindow->setView(_cameraView);

		// draw the stuff
		_renderWindow->clear();
		_renderWindow->draw(_playerShip);
		_renderWindow->display();
	}
}
