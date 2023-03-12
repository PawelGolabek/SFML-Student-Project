
#include "Game.h"
#include "Boss.h"
#include "Player.h"
#include "HitboxSprite.h"

#include <SFML/Graphics.hpp>

void Boss::init(std::vector<std::reference_wrapper<sf::Sprite>> &listOfSprites) {

	if (!texture.create(20, 20))
	{
		// error...
	}
	xPos = 400;
	yPos = 400;
	bossSprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
	bossSprite.setScale(sf::Vector2f(5.f, 5.f));
	std::string name2 = "Boss.png";
	bossSprite.setTexture(texture);
	texture.loadFromFile(name2);
	listOfSprites.push_back(bossSprite);

};

void Boss::shoot(const sf::Vector2f pos, const sf::Vector2f dir, Bullet& _bullet, std::vector<Bullet>& bullets) {
	_bullet.setXPos(pos.x);
	_bullet.setYPos(pos.y);

	_bullet.setDir(dir);

	_bullet.getSprite().setTextureRect(sf::IntRect(0, 0, 25, 25));
	_bullet.getSprite().setScale(sf::Vector2f(5.f, 5.f));
	bullets.push_back(_bullet);
};


void Boss::update(const int &frameTime, Player & player, std::vector<Bullet>& bullets, const sf::Time dt ) {


	bossSprite.setPosition(sf::Vector2f(xPos, yPos));
	bossSprite.setTextureRect(sf::IntRect((floor((frameTime % 4000) / 1000)) * 25, 0, 25, 25));

	bulletCounter += dt.asMicroseconds();

	if (bulletCounter > bulletDelay) {			// zmien na behavior potem
		bulletCounter -= bulletDelay;
		float scale = sqrt((player.getXpos() - xPos) * (player.getXpos() - xPos) + (player.getYpos() - yPos) * (player.getYpos() - yPos));

		float moveDirX = -(xPos - player.getXpos()) / scale;
		float moveDirY = -(yPos - player.getYpos()) / scale;

		sf::Vector2f a = sf::Vector2f(moveDirX, moveDirY);

		Bullet bullet1(xPos, yPos, a, a1f1BSpeed, 5); // zamien na dir
		Bullet bullet2(xPos, yPos, a, a1f1BSpeed, 5); // zamien na dir
		Bullet bullet3(xPos, yPos, rotateVector(a, 25), a1f1BSpeed, 5); // zamien na dir


		shoot(sf::Vector2f(xPos+80, yPos), rotateVector(a, 25), bullet1, bullets);
		shoot(sf::Vector2f(xPos, yPos), a, bullet2, bullets);
		shoot(sf::Vector2f(xPos-80, yPos), a, bullet3, bullets);
	}

};