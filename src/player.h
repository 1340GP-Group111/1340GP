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
private:
    char appearance;
    int level;
    int bombNum;
    int wealth;
    int x, y;

    void move(int);
};