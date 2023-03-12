#pragma once

#include <SFML/Graphics.hpp>

#include "HitboxSprite.h"

class Bullet {
private:
    float xPos;
    float yPos;
    sf::Vector2f dir;
    float speed;
    int damage;
    sf::Sprite sprite;
    HitboxSprite hitbox;

public:
    // Setters
    void setXPos(float x);
    void setYPos(float y);
    void setDir(sf::Vector2f d);
    void setSpeed(float s);
    void setDamage(int d);
    void setSprite(sf::Sprite s);

    // Getters
    float getXPos() const;
    float getYPos() const;
    sf::Vector2f getDir() const;
    float getSpeed() const;
    int getDamage() const;
    sf::Sprite getSprite();
    HitboxSprite getHitbox();

    // Constructors
    Bullet(const float& _xPos, const float& _yPos, const sf::Vector2f& _dir, const float& _speed, const int& _damage);
    ~Bullet();

    // Game logic
    void update(const sf::Time deltaTime);
};