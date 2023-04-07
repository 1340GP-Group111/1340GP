#ifndef PLAYER
#define PLAYER
#endif

#ifndef BLOCK
#include "block.h"
#endif
#include "gameMap.h"

class Player{
public:
    Player();
    Player(char, int, int, int, int, int);

    void move_left();
    void move_right();
    void move_down();

    void attack(Block &block);
    void bomb(Map &mp);
    
    //for shop
    int getWealth() const;
    void setWealth(int newWealth);
    char getAppearance() const;
    void setAppearance(char newAppearance);
    int getBombNum() const;
    void setBombNum(int newBombNum);
    int getAttack() const;
    void setAttack(int newAttack);
    
private:
    char appearance;
    int level;
    int bombNum;
    int wealth;
    int attack;
    int x, y;

    void move(int);
};

