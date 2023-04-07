#include "player.h"

Player::Player() {
    wealth = 0;
    appearance = '@';
    bombNum = 1;
    attack = 1;
}

int Player::getWealth() const {
    return wealth;
}

void Player::setWealth(int newWealth) {
    wealth = newWealth;
}

char Player::getAppearance() const {
    return appearance;
}

void Player::setAppearance(char newAppearance) {
    appearance = newAppearance;
}

int Player::getBombNum() const {
    return bombNum;
}

void Player::setBombNum(int newBombNum) {
    bombNum = newBombNum;
}

int Player::getAttack() const {
    return attack;
}

void Player::setAttack(int newAttack) {
    attack = newAttack;
}
