#pragma once

#include <SFML\Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

public:
	virtual void onEvent(sf::Event& event);
	virtual void render(sf::RenderWindow* window);
	virtual void update(sf::RenderWindow* window, float deltaTime);

protected:
	virtual void handleWindowCloseEvent() = 0;
	virtual void handleWindowSizeEvent(sf::Event::SizeEvent& event) = 0;
	virtual void handleKeyPressedEvent(sf::Event::KeyEvent& event) = 0;
	virtual void handleKeyReleasedEvent(sf::Event::KeyEvent& event) = 0;
};