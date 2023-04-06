#include <string>

#ifndef BLOCK
#include "block.h"
#endif

#ifndef MAP
#include "gameMap.h"
#endif

void printLine(string);
void printMap(const Map&, const Player&);
void flush();

string interact(string);
