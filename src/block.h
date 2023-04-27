#ifndef BLOCK
#define BLOCK

#include <string>

class Block{
private:
    std::string id;
    char appearance;
    char breaking_app;
    int max_health;
    int health;
    int value;
public:
    void setStatus(int status);

private:
    int status;

public:   
    std::string get_id() ;
    char get_appearance() ;
    char get_breaking_app();
    int get_health();
    int get_max_health();
    int get_value();
    int get_status() ;
    
    Block();
    Block(std::string id_, char appearance_, char breaking_app_, int health_, int value_, int status_);
    void copy(Block target);
    int attack(int damage);           //攻击方块。输入扣血量，如果方块已经是空的返回1, 攻击破坏成功返回2,未破坏返回0 
};

//health: Linear growth
//value:  Exponential growth 
//empty blocks:
extern Block b_00; 
//normal blocks:
extern Block b_0;
extern Block b_1;
extern Block b_2;
extern Block b_3;
extern Block b_4;
extern Block b_5;
extern Block b_6;
//special blocks with higher values:
extern Block s_0;
extern Block s_1;
extern Block s_2;
extern Block s_3;
extern Block s_4;
extern Block s_5;
extern Block s_6;
//obstacles that cannot be broken:
extern Block ob_0;
#endif 
