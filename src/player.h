#ifndef PLAYER
#define PLAYER

#include "block.h"
#include "gameMap.h"
#include <map>
class Map;
class Player{
public:
    //Constructor  skin--std::move(std::map <char,int>)
    Player(char appearance_,int level_,int bombNum_,int wealth_,int damage_, int oxygen_, int depth_, int x_, int y_, std::map<char, int> skin_):
            appearance(appearance_), level(level_), bombNum(bombNum_), wealth(wealth_),damage(damage_),oxygen(oxygen_),depth(depth_),x(x_),y(y_),skin(skin_) {}

    Player(): Player('@',1,1,0,1,10,0,0,0,skinInt()) {}
    Player(char appearance_, int level_, int bombNum_, int wealth_,int damage_): Player(appearance_,level_,bombNum_,wealth_,damage_,10,0,0,0,skinInt()) {}

    //Destructor
    ~Player()=default;

    //movement

//    void move_left();
//    void move_right();
//    void move_down();
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
	
	int getTime() const;
	void setTime(int t);
	
    int getOxygen() const;
    void setOxygen(int oxygen);

    int getLevel() const;
    void setLevel(int level);

    std::map <char,int> getSkin() const;
    void setSkin(std::map <char,int> skin);

    //Reset score, depth, x, y when starting a new game
    void playerInitialization(Map &mp);

private:
    char appearance;
    std::map <char,int> skin;
    int level;
    int bombNum;
    int wealth;
    int damage;
    int oxygen;      //max time
    int depth;       //absolute depth
    int x, y;        //location on the map
	int time;		//time
    void move(int);

    //skin initialization
    static std::map<char, int> skinInt() {

        std::map<char, int> TempMColor;
        TempMColor.insert(std::pair<char, int>('@',1));
        TempMColor.insert(std::pair<char, int>('#',0));
        TempMColor.insert(std::pair<char, int>('$',0));
        TempMColor.insert(std::pair<char, int>('%',0));
        TempMColor.insert(std::pair<char, int>('^',0));
        return TempMColor;

    }

};

#endif
