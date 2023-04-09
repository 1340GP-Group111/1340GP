#ifndef IO
#define IO

#include <string>
#include "block.h"
#include "gameMap.h"
#include "player.h"

void printLine(std::string);
void printMap(deque<vector<block>> deque_1,player p);
void flush();

std::string interact(std::string);
#endif
