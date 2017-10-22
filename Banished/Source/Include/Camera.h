#pragma once

#include "GameObject.h"

class Camera : public GameObject
{
private:
	sf::View _cameraView;

	sf::Vector2f	_cameraMovement;
	float			_cameraMovementSpeed;

public:
	Camera();
	Camera(float width, float height);
	~Camera();

public:
	const sf::View& getView() const;

public:
	virtual void onEvent(sf::Event& event) override;
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(sf::RenderWindow* window, float deltaTime) override;

protected:
	virtual void handleWindowCloseEvent() override;
	virtual void handleWindowSizeEvent(sf::Event::SizeEvent & event) override;
	virtual void handleKeyPressedEvent(sf::Event::KeyEvent & event) override;
	virtual void handleKeyReleasedEvent(sf::Event::KeyEvent & event) override;
};
