#include "block.h"

std::string Block::get_id() {
    return id;
}

char Block::get_appearance() {
    return appearance;
}

char Block::get_breaking_app() {
    return breaking_app;
}

int Block::get_max_health() {
    return max_health;
}

int Block::get_health() {
    return health;
}

int Block::get_value() {
    return value;
}

int Block::get_status() {
    return status;
}

Block::Block() {
    id = "white";
    appearance = '#';
    breaking_app = '*';
    health = 2;
    max_health = health;
    value = 1;
    status = 1;
}

Block::Block(std::string id_, char appearance_, char breaking_app_, int health_, int value_, int status_) {
    id = id_;
    appearance = appearance_;
    breaking_app = breaking_app_;
    health = health_;
    max_health = health_;
    value = value_;
    status = status_;
}

void Block::copy(Block target) { //鐢ㄦ潵缁欎竴涓柊鏂瑰潡璧嬪€硷紙gameMap閲岀敤锛?
    id = target.id;
    appearance = target.appearance;
    breaking_app = target.breaking_app;
    health = target.health;
    value = target.value;
    status = target.status;
}

int Block::attack(int damage) { //鏀诲嚮鏂瑰潡锛岃緭鍏ユ墸琛€鍊笺€傚鏋滄柟鍧楀凡缁忔槸绌虹殑杩斿洖1, 鏀诲嚮鐮村潖鎴愬姛杩斿洖2,鏈牬鍧忚繑鍥? 
    if (health > 0) {
        health = health - damage;
        if (health<=max_health/2){
        	status=2;
		}
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
//value:  Exponential growth 
//empty blocks:
Block b_00("white",'#','*',0,0,0); 
//normal blocks:
Block b_0("white",'#','*',2,1,1);
Block b_1("green",'#','*',3,2,1);
Block b_2("blue",'#','*',4,4,1);
Block b_3("yellow",'#','*',5,8,1);
Block b_4("red",'#','*',6,16,1);
Block b_5("pink",'#','*',7,32,1);
Block b_6("cyan",'#','*',8,64,1);
//special blocks with higher values:
Block s_0("white",'$','$',1,10,1);
Block s_1("green",'$','$',1,20,1);
Block s_2("blue",'$','$',1,40,1);
Block s_3("yellow",'$','$',1,80,1);
Block s_4("red",'$','$',1,160,1);
Block s_5("pink",'$','$',1,320,1);
Block s_6("cyan",'$','$',1,640,1);
//obstacles that cannot be broken:
Block ob_0("black",'#','*',999,1,1); 
