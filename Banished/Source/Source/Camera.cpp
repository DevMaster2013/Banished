#include "..\Include\Camera.h"

Camera::Camera()
	: Camera(800.0f, 600.0f)
{
}

Camera::Camera(float width, float height)
	: _cameraView(sf::View(sf::FloatRect(0.0f, 0.0f, width, height)))
	, _cameraMovement(0.0f, 0.0f)
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
	_cameraView.move(_cameraMovement * deltaTime * _cameraMovementSpeed);
}

void Camera::handleWindowCloseEvent()
{
}

void Camera::handleWindowSizeEvent(sf::Event::SizeEvent & event)
{
	_cameraView.setSize((float)event.width, (float)event.height);
}

void Camera::handleKeyPressedEvent(sf::Event::KeyEvent & event)
{
	if (event.code == sf::Keyboard::Key::Up)
		_cameraMovement.y = 1.0f;
	if (event.code == sf::Keyboard::Key::Down)
		_cameraMovement.y = -1.0f;
	if (event.code == sf::Keyboard::Key::Left)
		_cameraMovement.x = 1.0f;
	if (event.code == sf::Keyboard::Key::Right)
		_cameraMovement.x = -1.0f;
}

void Camera::handleKeyReleasedEvent(sf::Event::KeyEvent & event)
{
	if (event.code == sf::Keyboard::Key::Up)
		_cameraMovement.y = 0.0f;
	if (event.code == sf::Keyboard::Key::Down)
		_cameraMovement.y = 0.0f;
	if (event.code == sf::Keyboard::Key::Left)
		_cameraMovement.x = 0.0f;
	if (event.code == sf::Keyboard::Key::Right)
		_cameraMovement.x = 0.0f;
}
