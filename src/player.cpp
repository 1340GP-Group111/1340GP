#include "player.h"

//player move(private)
void Player::move(int direction){
    switch(direction)
    {
        case 1 :                 //move left
            x--;                 //x is the location in horizontal, x-1 move left 1 unit
            break;

        case 2 :                 //move down
            //The absolute depth of the player
                                // y is the location in vertical
            this->depth++;      //The value of y is always the center of the screen, so only change the depth
            break;

        case 3 :                 //move right
            x++;                 //x is the location in horizontal, x+1 move right 1 unit
            break;

        default:                 //default
            break;
    }
}

//movement(Does not judge whether to the edge)
//for shop but do not use now

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

void Player::move_left(Map &mp) {

    //Determine whether the square on the left is broken

    if(x>0) {
			Block &target =mp.mp[this->y][this->x-1];  //check obstacles

			if(target.get_status()==0)
				x=x-1;							       //if empty, move left
			else if(attack(target) == true)
				x=x-1;							       //if attack is successful, move left

		}
}

void Player::move_down(Map &mp) { //accepts a map parameter

    //Determine whether the block below is broken

    Block &target = mp.mp[this->y+1][this->x];     //The block we are going to attack

			if(target.get_status()==0){            //Is there a block
                //empty
                mp.generateLine(*this);            //move
				depth++;
			}
			else if(attack(target) == true){        //attack the block
                //break the block
				mp.generateLine(*this);
				depth++;
			}
}

void Player::move_right(Map &mp) {

    //Determine whether the square on the right is broken
    //Does it reach the edge
    if(x<19){                    //19 is the width of map

			Block &target = mp.mp[this->y][this->x+1];    //check obstacles

			if(target.get_status()==0)                //Is there a block
				x=x+1;                                //move
			else if(attack(target) == true)           //attack the block
				x=x+1;

		}
}

bool Player::attack(Block& target){                    //Deal with the target block

	int result = target.attack(1);                     //use attack in block.h
	if (result==2){                                    //break the block
		wealth = wealth + target.get_value();          //wealth increase, If the block is valuable
		return true;
	}else if(result==1){                               //did not break the block
        return true;                                  
	}                                                  // if return ture than player can move
	else {return false; }                              //can not move
}

//use bomb
void Player::bomb(Map &mp){    //accepts a map parameter
    
    if(bombNum <= 0) return;   //if player don't have bomb, return
    // nine blocks under player is broken
    // set block status to 0
    for (int i = y; i < y+3; i++){         
        for (int j = x-1; j < x+2; j++){
            
            if (j>=0 && j<=mp.width)        //whether to reach the border
               (mp.mp)[i][j].setStatus(0);  //set status
        }
    }
    bombNum--;                              //bombNum decrease by one
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
    this->y = mp.height/2;
    this->x = mp.width/2;
    this->time = this->getOxygen();
}

//level

int Player::getLevel() const{
    return level;
}

void Player::setLevel(int level){
     this->level = level;
}



//time used by timer
int Player::getTime() const{
	return time;
}
void Player::setTime(int time){
	this->time = time;
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

void Player::setDepth(int d){
	this->depth = d;
}

//skin

std::map <char,int> Player::getSkin() const{
    return skin;
}

//setSkin(std::move(std::map <char,int>))
void Player::setSkin(std::map <char,int> skin){
    this->skin=skin;
}
