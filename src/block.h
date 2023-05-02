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
    std::string get_id() const;
    char get_appearance() const;
    char get_breaking_app() const;
    int get_health() const;
    int get_max_health() const;
    int get_value() const;
    int get_status() const;
    
    Block();
    Block(std::string id_, char appearance_, char breaking_app_, int health_, int value_, int status_);
    void copy(Block target);
    int attack(int damage);           //Attack the block. Input the damage. Failed to break it:return 0; Empty:return 1; Broken:return 2
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
extern Block a;
extern Block space;
//These are merchants
extern Block MM;
extern Block MA;
extern Block ML;
extern Block MO;
#endif 
