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
    if(x>0) {
			Block &target =mp.mp[this->y][this->x-1];//check obstacles
			if(target.get_status()==0)
				x=x-1;							//if empty, move left
			else if(attack(target) == true)
				x=x-1;							//if attack is successful, move left
		}

}

void Player::move_down(Map &mp) {
    //Determine whether the block below is broken
    Block &target = mp.mp[this->y+1][this->x];
			if(target.get_status()==0){
				mp.generateLine(*this); 
				depth++;
			}
			else if(attack(target) == true){
				mp.generateLine(*this);
				depth++;
			}
}

void Player::move_right(Map &mp) {
    //Determine whether the square on the right is broken
    if(x<20){ //width
			Block &target = mp.mp[this->y][this->x+1];//check obstacles
			if(target.get_status()==0)
				x=x+1;
			else if(attack(target) == true)
				x=x+1;
		}
}

bool Player::attack(Block& target){ //Deal with the target block

	int result = target.attack(1);
	if (result==2){
		wealth = wealth + target.get_value();
		return true;
	}
	else if(result==1){
		return true;
	}
	else return false;
	}

//player 下面九格status=0
void Player::bomb(Map &mp) const{
    for (int i = y; i < y+3; i++){
        for (int j = x-1; j < x+2; j++){
            //whether to reach the border
            if (j>=0 && j<=mp.width)
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


//time
int Player::getTime() const{
	return time;
}
void Player::setTime(int t){
	this->time = t;
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
