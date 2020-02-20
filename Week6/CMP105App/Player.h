#include "Framework/GameObject.h"
#pragma once
class Player: public GameObject
{

public:

	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	float scale;
	sf::Vector2f jumpVector;
	bool isJumping;

	Player();
	~Player();
	void update(float, sf::Vector2u);
	void handleInput(float);


};

