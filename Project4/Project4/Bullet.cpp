#include "Bullet.h"

Bullet::Bullet(const float& _xPos, const float& _yPos, const sf::Vector2f& _dir, const float& _speed, const int& _damage) {

	xPos = _xPos;
	yPos = _yPos;
	dir = _dir;
	speed = _speed;
	damage = _damage;

    HitboxSprite hitbox;

    std::string name = "Bullet.png";
    sf::Texture *texture = new sf::Texture;

    sprite.setTexture(*texture);
    sprite.setScale(sf::Vector2f(1.0f, 1.0f));
    sprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
    sprite.setPosition(sf::Vector2f(xPos, yPos));
    (*texture).loadFromFile(name);

};


// Setters
void Bullet::setXPos(float x) {
    xPos = x;
}

void Bullet::setYPos(float y) {
    yPos = y;
}

void Bullet::setDir(sf::Vector2f d) {
    dir = d;
}

void Bullet::setSpeed(float s) {
    speed = s;
}

void Bullet::setDamage(int d) {
    damage = d;
}

void Bullet::setSprite(sf::Sprite s) {
    sprite = s;
}

// Getters
float Bullet::getXPos() const {
    return xPos;
}

float Bullet::getYPos() const {
    return yPos;
}

sf::Vector2f Bullet::getDir() const {
    return dir;
}

float Bullet::getSpeed() const {
    return speed;
}

int Bullet::getDamage() const {
    return damage;
}

sf::Sprite Bullet::getSprite(){
    return sprite;
}
HitboxSprite Bullet::getHitbox() {
    return hitbox;

};

Bullet::~Bullet() {



};


// Game Logic

void Bullet::update(const sf::Time deltaTime) {
    xPos += dir.x * speed * deltaTime.asSeconds();
    yPos += dir.y * speed * deltaTime.asSeconds();
    sprite.setPosition(sf::Vector2f(xPos, yPos));
    hitbox.setHitbox({ xPos, yPos, 25.f, 25.f });

};