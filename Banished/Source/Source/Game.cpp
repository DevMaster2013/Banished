#include "..\Include\Game.h"
#include "..\Include\Camera.h"
#include "..\Include\GameWorld.h"

Game::Game()
	: _renderWindow(nullptr)
	, _renderThread(nullptr)
	, _updateThread(nullptr)
{	
	
}

Game::~Game()
{
	
}

bool Game::init()
{
#ifdef _DEBUG
	_renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Banished");
#else
	_renderWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Banished", sf::Style::Fullscreen);
#endif // DEBUG

	_renderWindow->setVerticalSyncEnabled(true);	

	_gameObjects["MainCamera"] = new Camera(800.0f, 600.0f);
	_gameObjects["GameWorld"] = new GameWorld();	

	return true;
}

void Game::run()
{
	// Initialize all gameobjects
	for each (auto& gameObject in _gameObjects)
		gameObject.second->init();

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

void Game::release()
{
	_updateThread->wait();
	_renderThread->wait();

	for each (auto& gameObject in _gameObjects)
		delete gameObject.second;
	_gameObjects.clear();
	delete _renderWindow;
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

			// handle the event in game objects
			for each (auto& gameObject in _gameObjects)
				gameObject.second->onEvent(event);
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

		// update all game objects
		for each (auto& gameObject in _gameObjects)
			gameObject.second->update(_renderWindow, elapsedTime);
	}
}

void Game::render()
{
	// Activate the window
	_renderWindow->setActive(true);

	// Get reference to the main camera
	Camera* mainCamera = ((Camera*)_gameObjects["MainCamera"]);

	// the rendering loop
	while (_renderWindow->isOpen())
	{
		// draw the stuff
		_renderWindow->setView(mainCamera->getView());
		_renderWindow->clear();

		// Render all gameobject
		for each (auto& gameObject in _gameObjects)
			gameObject.second->render(_renderWindow);

		_renderWindow->display();
	}
}
