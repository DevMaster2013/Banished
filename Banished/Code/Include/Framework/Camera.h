#pragma once

#include "GameObject.h"

class Camera : public GameObject
{
private:
	sf::View	_cameraView;
	float		_cameraMovementSpeed;

public:
	Camera();
	Camera(float width, float height);
	virtual ~Camera();

public:
	const sf::View& getView() const;

public:
	virtual void onEvent(sf::Event& event) override;
	virtual void render(sf::RenderWindow* window) override;
	virtual void update(sf::RenderWindow* window, float deltaTime) override;

protected:
	virtual void handleWindowSizeEvent(sf::Event::SizeEvent & event) override;

private:
	void handleCameraMovement(float deltaTime);
};
