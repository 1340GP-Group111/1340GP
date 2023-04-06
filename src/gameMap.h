#ifndef MAP
#define MAP
#endif

#ifndef PLAYER
#include "player.h"
#endif

class Map{
public:
    deque<vector<Block>> mp;

    Map();
    Map(int, int);

    void clear(int, int);
    void clear(int, int, int, int);
    void generateLine(const Player&);
    void pop(int);
private:
    int width, height;
};