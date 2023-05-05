#include "block.h"

std::string Block::get_id() const{
    return id;
}

char Block::get_appearance() const{
    return appearance;
}

char Block::get_breaking_app() const{
    return breaking_app;
}

int Block::get_max_health() const{
    return max_health;
}

int Block::get_health() const{
    return health;
}

int Block::get_value() const{
    return value;
}

int Block::get_status() const{
    return status;
}

Block::Block() {		//Default constructor, generate a normal white block
    id = "white";
    appearance = '#';
    breaking_app = '*';
    health = 2;
    max_health = health;
    value = 1;
    status = 1;
}

Block::Block(std::string id_, char appearance_, char breaking_app_, int health_, int value_, int status_) {	//Constructor
    id = id_;
    appearance = appearance_;
    breaking_app = breaking_app_;
    health = health_;
    max_health = health_;
    value = value_;
    status = status_;
}

void Block::copy(Block target) { //For game map, quickly copy properties to a new block）
    id = target.id;
    appearance = target.appearance;
    breaking_app = target.breaking_app;
    health = target.health;
    value = target.value;
    status = target.status;
}

int Block::attack(int damage) { //Attack the block. Input the damage.
    if (health > 0) {
        //change the status of the block
        health = health - damage;
        //if the block is half broken
        if (health<=max_health/2){
        	status=2;
		}
        //if the block is broken
        if (health <= 0) {
            status = 0;
            health = 0;
            return 2;
        }
        else {
            return 0;
        }
    }
    else {
        return 1;
    }
}

void Block::setStatus(int sta){
    Block::status = sta;
}

//health: Linear growth
//value:  Exponential growth and price ceiling
//empty blocks:
Block b_00("white",'#','*',0,0,0); 
//normal blocks:
Block b_0("white",'#','*',6,1,1);
Block b_1("green",'#','*',9,2,1);
Block b_2("blue",'#','*',12,4,1);
Block b_3("yellow",'#','*',15,8,1);
Block b_4("red",'#','*',18,16,1);
Block b_5("pink",'#','*',21,32,1);
Block b_6("cyan",'#','*',24,64,1);
//special blocks with higher values:
Block s_0("white",'$','$',1,10,1);
Block s_1("green",'$','$',1,20,1);
Block s_2("blue",'$','$',1,40,1);
Block s_3("yellow",'$','$',1,80,1);
Block s_4("red",'$','$',1,160,1);
Block s_5("pink",'$','$',1,320,1);
Block s_6("cyan",'$','$',1,640,1);
//obstacles that cannot be broken:
//add obstacles to prevent the player from destructing the camp base& add playability to main game
Block ob_0("black",'X','*',999,1,1);    //can't be broke
Block a("black",'#','#',9999,1,3);      // walls of the camp base
Block MM("red",'M','M',9999,1,4);       //bomb merchants
Block space("white",' ',' ',0,0,0);
Block ML("red",'L','L',9999,1,5);       //attack merchants
Block MA("red",'A','A',9999,1,6);      //skin merchants
Block MO("red",'O','O',9999,1,7);       //oxygen merchants
