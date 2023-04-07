#include <string>

#ifndef BLOCK
#include "block.h"
#endif

#ifndef MAP
#include "gameMap.h"
#endif

#ifndef PLAYER
#include "player.h"
#endif

#ifndef IO
#include "io.h"
void printLine(std::string);
void printMap(deque<vector<block>> deque_1,player p);
void flush();

std::string interact(std::string);
#endif
