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

void printLine(std::string);
void printMap(const Map&, const Player&);
void flush();

std::string interact(std::string);
