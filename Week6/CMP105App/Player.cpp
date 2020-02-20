#include "Player.h"

Player::Player() 
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = true;
}
Player::~Player() {}
void Player::update(float dt, sf::Vector2u winsize) 
{
	

	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;	 //ut+ 1/2at^2
	stepVelocity += gravity *dt;	// v = u + at  note the += is not =
	setPosition(getPosition() +pos);
	// Check for collision with bottom of window
	if(getPosition().y >= winsize.y-100)
	{
		isJumping = false;
		setPosition(getPosition().x, winsize.y - 100);
		stepVelocity= sf::Vector2f(0, 0);
	}
}
void Player::handleInput(float dt)
{
	if(input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true; 
		}
	}
	
	if (input->isMouseLDown() )
	{
		setPosition(input->getMouseX(), input->getMouseY());
	}
}

