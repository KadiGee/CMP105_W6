#include "Ball.h"
Ball::Ball() 
{
	speed = 50.f;
	acceleration = 50.f;
	target = sf::Vector2f(600, 300)
}

Ball::~Ball() {}