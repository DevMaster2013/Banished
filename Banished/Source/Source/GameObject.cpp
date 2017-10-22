#include "..\Include\GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::onEvent(sf::Event & event)
{
	if (event.type == sf::Event::Closed)
		handleWindowCloseEvent();
	if (event.type == sf::Event::Resized)
		handleWindowSizeEvent(event.size);
	if (event.type == sf::Event::KeyPressed)
		handleKeyPressedEvent(event.key);
	if (event.type == sf::Event::KeyReleased)
		handleKeyReleasedEvent(event.key);
}

void GameObject::render(sf::RenderWindow * window)
{
}

void GameObject::update(sf::RenderWindow * window, float deltaTime)
{
}
