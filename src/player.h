#ifndef PLAYER
#define PLAYER       //avoid multiple definitions

//import
#include "block.h"
#include "gameMap.h"
#include <map>

class Map;

class Player{

public:

    //Constructor
    //accept all parameters
    //skin--std::move(std::map <char,int>)
    Player(char appearance_,int level_,int bombNum_,int wealth_,int damage_, int oxygen_, int depth_, int x_, int y_, std::map<char, int> skin_):
            appearance(appearance_), level(level_), bombNum(bombNum_), wealth(wealth_),damage(damage_),oxygen(oxygen_),depth(depth_),x(x_),y(y_),skin(skin_) {}

    //default
    //set the initial parameter
    Player(): Player('@',1,1,0,1,10,0,0,0,skinInt()) {}

    //for loadFromFile
    //accept appearance,level,bombNum,wealth,damage
    Player(char appearance_, int level_, int bombNum_, int wealth_,int damage_): Player(appearance_,level_,bombNum_,wealth_,damage_,10,0,0,0,skinInt()) {}

    //Destructor
    ~Player()=default;

    //movement

    void move_left();
    void move_right();
    void move_down();

    void move_left(Map &mp);   //Judging whether to the edge
    void move_right(Map &mp);  //Judging whether to the edge
    void move_down(Map &mp);   //Judging whether to the edge

    //attack
    bool attack(Block& target);

    //bomb
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
    void setDepth(int d);

    //time
    //time used by timer
    int getTime() const;
    void setTime(int time);

    int getOxygen() const;
    void setOxygen(int oxygen);

    int getLevel() const;
    void setLevel(int level);


    // get skin map
    std::map <char,int> getSkin() const;

    //map to store the appearance
    //pair.first store appearance
    //pair.second store status
    //0-> you don't have this skin
    //1-> you have this skin
    //2-> the skin you are wearing
    void setSkin(std::map <char,int> skin);

    //Reset wealth, depth, x, y when starting a new game
    void playerInitialization(Map &mp);

private:

    char appearance;          // the skin you are wearing
    std::map <char,int> skin; // store skin
    int level;
    int bombNum;     //how many bombs you have
    int wealth;      //how much money you have
    int damage;      //your attack power
    int oxygen;      //max time
    int depth;       //absolute depth
    int x;           //location(horizontal) on the map
    int y;           //location(vertical) on the map
    int time;		 //time

    void move(int);  //method move(private)

    //skin initialization(static)
    static std::map<char, int> skinInt() {

        std::map<char, int> TempMColor;  //temp

        //skin
        TempMColor.insert(std::pair<char, int>('@',1));   //initial skinI(@)
        TempMColor.insert(std::pair<char, int>('#',0));   //Purchasable(#) skins not owned
        TempMColor.insert(std::pair<char, int>('$',0));   //Purchasable($) skins not owned
        TempMColor.insert(std::pair<char, int>('%',0));   //Purchasable(%) skins not owned
        TempMColor.insert(std::pair<char, int>('^',0));   //Purchasable(^) skins not owned

        return TempMColor;                //return to Constructor

    }
};

#endif
