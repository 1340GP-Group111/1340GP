#include <vector>
#include <deque>
#include <random>
#include <ctime>

#ifndef MAP
#define MAP
#endif

#ifndef PLAYER
#include "player.h"
#endif

class Map{
public:
    std::deque<std::vector<Block>> mp;
    Map();
    Map(int, int);
    void generateLine(const Player&);
    void show_map(const Player&);
private:
    int width, height;
};
class Map{
