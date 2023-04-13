#ifndef MAP
#define MAP

#include <vector>
#include <deque>
#include <random>
#include <ctime>
#include "player.h"

class Map{
public:
    std::deque<std::vector<Block>> mp;
    Map();
    Map(int, int);
    void generateLine(const Player&);
    void show_map(const Player&);
private:
    int width, height;
public:
    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);
};

#endif