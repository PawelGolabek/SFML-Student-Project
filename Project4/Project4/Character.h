#pragma once

#include "HitboxSprite.h"

class Character {
protected:
	float xPos;
	float yPos;
	int hp;
	int lives;
	HitboxSprite hitbox;
public:

	Character();
	Character(int _hp);
	Character(int _hp, const float _xPos, const float _yPos, const int _lives);
	void init();
	void move();

	float getXpos();
	float getYpos();
	int getHp();
	int getLives();

	void setXpos(const float& _xPos);
	void setYpos(const float &_yPos);
	void setHp(const int &_hp);
	void setLives(const int &_lives);

};

