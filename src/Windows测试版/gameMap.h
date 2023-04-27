#ifndef MAP
#define MAP

#include <vector>
#include <deque>
#include <random>
#include <ctime>
#include <iostream>
#include "player.h"
class Player;
class Map{
public:
    int width;
	int height;
    std::deque<std::vector<Block> > mp;

    Map();

    Map(int, int);

    void generateLine(const Player& p);

    void show_map(const Player& p);
};
#endif
