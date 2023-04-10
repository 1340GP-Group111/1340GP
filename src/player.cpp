#include "player.h"

//player move(private)
void Player::move(int direction){
    switch(direction)
    {
        case 1 : //move left
            x--;
        case 2 : //move down
            y++;
        case 3 : //move right
            x++;

    }
}

//movement(Does not judge whether to the edge)

void Player::move_left() {
    if ( x != 0 )
        move(1);
}

void Player::move_down() {
    move(2);
    this->depth++;
}

void Player::move_right() {
    move(3);
}

//movement(Judging whether to the edge)--refactoring function

void Player::move_down(Map &mp) {
    if ( y < mp.getHeight)
        move_down();
}

void Player::move_right(Map &mp) {
    if ( x < mp.getWidth )
        move(3);
}

//player attack

void Player::attack(Block &block,auto direction){
     int attackStatus = block.attack(this->damage);
     if ( attackStatus != 0 ){
         switch(direction)
         {
             case "l" :
                 move_left()
             case "d" :
                 move_down()
             case "r" :
                 move_right()
         }
     }
}

//player 下面九格status=0
void Player::bomb(Map &mp){
    for (i = x-1; i < x+2; i++){
        for (j = y-1; j < y+2; y++){
            (mp.mp)[i][j].setStatus=0
        }
    }
}

//getters and setters
//wealth

int Player::getWealth() const{
    return wealth;
}

void Player::setWealth(int wealth) {
    this->wealth = wealth;
}
//appearance

char Player::getAppearance() const{
    return appearance;
}

void Player::setAppearance(char appearance) {
    ehis->appearance = appearance;
}


//bombNum

int Player::getBombNum() const{
    return bombNum;
}

void Player::setBombNum(int bombNum) {
    this->bombNum = bombNum;
}

//damage

int Player::getDamage(){
    return Damage;
}

void Player::setDamage(int damage) {
    this->damage = damage;
}

//Location

int Player::getX(){
    return x;
}

int Player::getY(){
    return y;
}

void Player::setLocation(int x,int y){
    this->x = x;
    this->y = y;
}

//score

int Player::getScore(){
    return score;
}

void Player::setScore(int score){
    this->score = score;
}

//Reset score, depth, x, y when starting a new game

void Player::playerInitialization(Map &mp){
    this->score = 0;
    this->depth =0;
    this->y = 0;
    this->x = mp.getWidth/2;
}
