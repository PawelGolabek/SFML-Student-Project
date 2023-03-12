#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

#include "Character.h"
#include "Bullet.h"
#include "HitboxSprite.h"


class Player : public Character{
public:
	void init();
	void shoot();
	void movement(const sf::Time deltaTime);
	const float movementSpeed = 200;
	HitboxSprite hitbox;

	void collisions(const sf::Time deltaTime,std::vector<Bullet>& bullets);
};