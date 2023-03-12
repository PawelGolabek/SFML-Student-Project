#include "Character.h"
#include "HitboxSprite.h"

Character::Character() {
	xPos = 100;
	yPos = 100;
	hp = 100;
	lives = 3;
}

Character::Character(int _hp) {
	xPos = 100;
	yPos = 100;
	hp = _hp;
	lives = 3;
}

Character::Character(int _hp, const float _xPos, const float _yPos, const int _lives) {
	xPos = _xPos;
	yPos = _yPos;
	hp = _hp;
	lives = _lives;
}

void Character::init() {

}

float Character::getXpos() {
	return xPos;
}
float Character::getYpos() {
	return yPos;
}
int Character::getHp() {
	return hp;
}
int Character::getLives() {
	return lives;
}


void Character::setXpos(const float& _xPos) {
	xPos = _xPos;
};
void Character::setYpos(const float& _yPos) {
	yPos = _yPos;

};
void Character::setHp(const int& _hp) {
	xPos = _hp;

};
void Character::setLives(const int& _lives) {
	lives = _lives;
};