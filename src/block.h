#include <string>

#ifndef BLOCK
#define BLOCK
#endif

class Block{
public:
    Block();
    Block(char, string, int, int, int);
private:
    char appearance;
    string id;
    int blood;
    int value;
    int status;
};