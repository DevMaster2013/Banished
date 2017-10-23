#include "Framework\Camera.h"

Camera::Camera()
	: Camera(800.0f, 600.0f)
{
}

Camera::Camera(float width, float height)
	: _cameraView(sf::View(sf::FloatRect(0.0f, 0.0f, width, height)))
	, _cameraMovementSpeed(100.0f)
{
}

Camera::~Camera()
{
}

const sf::View& Camera::getView() const
{
	return _cameraView;
}

void Camera::onEvent(sf::Event & event)
{
	GameObject::onEvent(event);
}

void Camera::render(sf::RenderWindow * window)
{
}

void Camera::update(sf::RenderWindow * window, float deltaTime)
{
	handleCameraMovement(deltaTime);
}

void Camera::handleWindowSizeEvent(sf::Event::SizeEvent & event)
{
	_cameraView.setSize((float)event.width, (float)event.height);
	GameObject::handleWindowSizeEvent(event);
}

void Camera::handleCameraMovement(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		movement.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		movement.y += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += 1;
	_cameraView.move(movement * deltaTime * _cameraMovementSpeed);
}
