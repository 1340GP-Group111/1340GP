#ifndef BLOCK
#define BLOCK

#include <string>

class Block{
private:
    std::string id;
    char appearance;
    char breaking_app;
    int health;
    int value;
    int status;

public:   
    std::string get_id();
    char get_appearance();
    char get_breaking_app();
    int get_health();
    int get_value();
    int get_status();
    
    Block();
    Block(std::string id_, char appearance_, char breaking_app_, int health_, int value_, int status_);
    void copy(Block target);
    int attack(int damage);           //攻击方块。输入扣血量，如果方块已经是空的返回1, 攻击破坏成功返回2,未破坏返回0 
};

//health:线性增长
//value:指数增长 
//一些gameMap需要用到的全局Block
//normal blocks 
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

#endif
