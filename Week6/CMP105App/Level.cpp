#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	texture.loadFromFile("gfx/Beach_Ball.png");

	ball.setTexture(&texture);
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(800, 0);
	ball.setInput(input);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	ball.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2u winsize = window->getSize();
	ball.update(dt, winsize);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}