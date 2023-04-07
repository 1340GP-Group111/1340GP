#include <string>

#ifndef BLOCK
#define BLOCK
#endif

class Block{
public:
    Block();
    Block(char, std::string, int, int, int);
private:
    char appearance;
    std::string id;
    int blood;
    int value;
    int status;
};