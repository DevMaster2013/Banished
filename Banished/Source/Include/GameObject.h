#pragma once

#include <SFML\Graphics.hpp>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

public:
	virtual void onEvent(sf::Event& event);
	virtual bool init();
	virtual void render(sf::RenderWindow* window);
	virtual void update(sf::RenderWindow* window, float deltaTime);
	virtual void release();

protected:
	virtual void handleWindowCloseEvent();
	virtual void handleWindowSizeEvent(sf::Event::SizeEvent& event);
	virtual void handleKeyPressedEvent(sf::Event::KeyEvent& event);
	virtual void handleKeyReleasedEvent(sf::Event::KeyEvent& event);
};