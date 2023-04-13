#ifndef PLAYER
#define PLAYER

#include "block.h"
#include "gameMap.h"

class Player{
public:
    //Constructor
    Player(char appearance_,int level_,int bombNum_,int wealth_,int damage_, int score_, int depth_, int x_, int y_):
             appearance(appearance_), level(level_), bombNum(bombNum_), wealth(wealth_),damage(damage_),score(score_),depth(depth_),x(x_),y(y_) {}

    Player(): Player('@',1,1,0,1,0,0,0,0) {}
    Player(char appearance_, int level_, int bombNum_, int wealth_,int damage_): Player(appearance_,level_,bombNum_,wealth_,damage_,0,0,0,0) {}

    //Destructor
    ~Player() {}

    //movement

    void move_left();
    void move_right();
    void move_down();
    void move_right(Map &mp);  //Judging whether to the edge
    void move_down(Map &mp);   //Judging whether to the edge

    //player attack

    void attack(Block &block, const char &direction);
    void bomb(Map &mp);

    //getters and setters

    int getWealth() const;
    void setWealth(int wealth);

    char getAppearance() const;
    void setAppearance(char appearance);

    int getBombNum() const;
    void setBombNum(int bombNum);

    int getDamage() const;
    void setDamage(int damage);

    int getX() const;
    int getY() const;
    void setLocation(int x,int y);

    int getDepth() const;

    int getScore() const;
    void setScore(int score);

    //Reset score, depth, x, y when starting a new game
    void playerInitialization(Map &mp);

private:
    char appearance;
    int level;
public:
    int getLevel() const;

    void setLevel(int level);

private:
    int bombNum;
    int wealth;
    int damage;
    int score;       //current game score
    int depth;       //absolute depth
    int x, y;        //location on the map

    void move(int);

};

#endif

