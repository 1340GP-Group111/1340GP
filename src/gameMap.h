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
    Map();				//default constructor
    Map(int, int);			//constructor, input the height and width.
    void generateLine(const Player& p);	//generate a new line according to the player's depth
    void show_map(const Player& p);
};
#endif
