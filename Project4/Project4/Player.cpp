
#include <iostream>
#include <vector>

#include "Player.h"
#include "HitboxSprite.h"
#include "Bullet.h"


void Player::shoot() {


}

void Player::init() {

	HitboxSprite hitbox;

};

void Player::movement(const sf::Time deltaTime) {


	bool W = false, A = false, S = false, D = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		W = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		A = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		S = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		D = true;
	}

	if (W) {
		setYpos(getYpos() - (movementSpeed * deltaTime.asSeconds()));
		std::cout << getYpos();
		// check for collisions

	}
	if (A) {
		setXpos(getXpos() - (movementSpeed * deltaTime.asSeconds()));
		std::cout << getXpos();
		// check for collisions

	}
	if (S) {
		setYpos(getYpos() + (movementSpeed * deltaTime.asSeconds()));
		std::cout << getYpos();
		// check for collisions

	}
	if (D) {
		setXpos(getXpos() + (movementSpeed * deltaTime.asSeconds()));
		std::cout << getXpos();
		// check for collisions

	}
	hitbox.setHitbox({ xPos, yPos, 32.f, 32.f });
}


void Player::collisions(const sf::Time deltaTime, std::vector<Bullet>& bullets) {
	bool colliding;
	int i = 0;
	for (auto& bullet : bullets) {
		colliding = hitbox.getGlobalHitbox().intersects((bullet.getHitbox()).getGlobalHitbox());

		if (colliding) {
			bullets.erase(bullets.begin() + i);
			std::cout << "Coliding";
		}
		i++;
	}

}