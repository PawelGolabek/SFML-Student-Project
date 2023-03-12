#pragma once

#include <SFML/Graphics.hpp>
#include <chrono>

#include "Character.h"
#include "Bullet.h"
#include "Player.h"


class Boss : public Character {
private:
	float bulletCounter = 0;
	float bulletDelay = 500000;
	float a1f1BSpeed = 120;
public:
	sf::Texture texture;
	sf::Sprite bossSprite;

	void shoot(const sf::Vector2f pos, const sf::Vector2f dir, Bullet& _bullet, std::vector<Bullet>& bullets);
	void init(std::vector<std::reference_wrapper<sf::Sprite>>& listOfSprites);
	void update(const int& frameTime, Player &player, std::vector<Bullet>& bullets, const sf::Time deltaTime);

};