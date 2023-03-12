#include <cmath>
#include <iostream>

#include "Game.h"
void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;

	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
}

Game::~Game() {
	delete this->window;
}

void Game::render() {
	this->window->clear();
	this->window->display();
}

sf::Vector2f rotateVector(sf::Vector2f &vec, int degree) {
    degree = (360 + degree) % 360;
    std::cout << vec.x << " " << vec.y << " ";
    vec.x = cos((degree / 360.0) * 3.14) * vec.x - sin((degree / 360.0) * 3.14) * vec.y;
    vec.y = sin((degree / 360.0) * 3.14) * vec.x + cos((degree / 360.0) * 3.14) * vec.y;
   // move direction into normalised vector
    float scale = sqrt(abs(vec.x * vec.x + vec.y * vec.y));
    if (scale != 0) {
        vec.x = vec.x / scale;
        vec.y = vec.y / scale;
    }
    std::cout << vec.x << " " << vec.y << std::endl;
    return vec;
}