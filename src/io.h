#ifndef IO
#define IO

#include <string>
#include <vector>
#include <deque>
#include "block.h"
#include "gameMap.h"
#include "player.h"

void printLine(std::string);
void printMap(std::deque<std::vector<Block>> deque_1,Player p);
void flush();

std::string interact(std::string);

const long long HASH = 998244853, MOD = (long long)1e9+7;
long long encode(const std::string&);
int saveToFile(const Player&);
int loadFromFile(Player&);
#endif
