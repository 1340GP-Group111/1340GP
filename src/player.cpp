#include "player.h"

//player move(private)
void Player::move(int direction){
    switch(direction)
    {
        case 1 : //move left
            x--;
            break;
        case 2 : //move down
            //The absolute depth of the player
            this->depth++;
            break;
        case 3 : //move right
            x++;
            break;
        default:
            break;
    }
}

//movement(Does not judge whether to the edge)

//void Player::move_left() {
//    if ( x != 0 )
//        move(1);
//}
//
//void Player::move_down() {
//    move(2);
//    this->depth++;
//}
//
//void Player::move_right() {
//    move(3);
//}

//movement(Judging whether to the edge)--refactoring function

void Player::move_left(Map &mp) {
    //Determine whether the square on the left is broken
    int attackStatus = mp.mp[this->y][this->x-1].attack(this->damage);
    //The block was compromised or was originally an empty block
    if ( attackStatus != 0 ){
        //whether to reach the border
        if (x != 0)
            move(1);//move left
    }

}

void Player::move_down(Map &mp) {
    //Determine whether the block below is broken
    int attackStatus = mp.mp[this->y+1][this->x].attack(this->damage);
    //The block was compromised or was originally an empty block
    if ( attackStatus != 0 ){
        move(2);//move down
    }
}

void Player::move_right(Map &mp) {
    //Determine whether the square on the right is broken
    int attackStatus = mp.mp[this->y][this->x-1].attack(this->damage);
    //The block was compromised or was originally an empty block
    if ( attackStatus != 0 ){
        //whether to reach the border
        if ( x < Map::WIDTH)
            move(3);//move right
    }
}

//player 下面九格status=0
void Player::bomb(Map &mp) const{
    for (int i = y-1; i < y+2; i++){
        for (int j = x-1; j < x+2; j++){
            //whether to reach the border
            if (j>=0 && j<=Map::WIDTH)
               (mp.mp)[i][j].setStatus(0);
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
    this->appearance = appearance;
}


//bombNum

int Player::getBombNum() const{
    return bombNum;
}

void Player::setBombNum(int bombNum) {
    this->bombNum = bombNum;
}

//damage

int Player::getDamage() const{
    return damage;
}

void Player::setDamage(int damage) {
    this->damage = damage;
}

//Location

int Player::getX() const{
    return x;
}

int Player::getY() const{
    return y;
}

void Player::setLocation(int x,int y){
    this->x = x;
    this->y = y;
}

//Reset score, depth, x, y when starting a new game

void Player::playerInitialization(Map &mp){
    this->depth =0;
    this->y = Map::HEIGHT/2;
    this->x = Map::WIDTH/2;
}

//level

int Player::getLevel() const{
    return level;
}

void Player::setLevel(int level){
     this->level = level;
}

//oxygen

int Player::getOxygen() const{
    return oxygen;
}

void Player::setOxygen(int oxygen){
    this->oxygen = oxygen;
}

//depth

int Player::getDepth() const{
    return depth;
}

//skin

std::map <char,int> Player::getSkin() const{
    return skin;
}

//setSkin(std::move(std::map <char,int>))
void Player::setSkin(std::map <char,int> &&skin){
    this->skin=skin;
}
