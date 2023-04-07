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
    value = 1;
    status = 1;
}

Block::Block(std::string id_, char appearance_, char breaking_app_, int health_, int value_, int status_) {
    id = id_;
    appearance = appearance_;
    breaking_app = breaking_app_;
    health = health_;
    value = value_;
    status = status_;
}

void Block::copy(Block target) { //用来给一个新方块赋值（gameMap里用）
    id = target.id;
    appearance = target.appearance;
    breaking_app = target.breaking_app;
    health = target.health;
    value = target.value;
    status = target.status;
}

int Block::attack(int damage) { //攻击方块，输入扣血值。如果方块已经是空的返回1, 攻击破坏成功返回2,未破坏返回0 
    if (health > 0) {
        health = health - damage;
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
