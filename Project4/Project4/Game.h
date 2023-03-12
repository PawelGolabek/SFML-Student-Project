#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
private:
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

public:
	Game();
	virtual ~Game();

	void initWindow();
	void update();
	void render();
	void Events();


};


sf::Vector2f rotateVector(sf::Vector2f &vec, int degree);