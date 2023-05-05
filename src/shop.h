#ifndef SHOP_H
#define SHOP_H
#include "ui.h"
#include "block.h"
#include "player.h"
#include <vector>
#include <curses.h>

class Shop {
    private:
        std::vector<char> availableSkins;
        int APPEARANCE_PRICE;
        int BOMB_PRICE;
        int ATTACK_PRICE;
        int TIME_PRICE;
    public:
        Shop();
        void showShop(Player &player) const;
        void buyAppearance(Player &player);
        void equipAppearance(Player &player);
        void buyBomb(Player &player);
        void buyAttack(Player &player);
        void buyTime(Player &player, int time);
        static void exitShop();
    
        int x; // For player to move
    	int y;	
    	void set_xy(int x_,int y_);
    	void move_up(std::deque<std::vector<Block> >& mp,Player& real_p);
    	void move_down(std::deque<std::vector<Block> >& mp,Player& real_p);
    	void move_left(std::deque<std::vector<Block> >& mp,Player& real_p);
    	void move_right(std::deque<std::vector<Block> >& mp,Player& real_p);
    	void interact(const Block& tar,Player& real_p);
};

class ShoppingMap{
    public:
        ShoppingMap(int width_,int height_);
        void show_map(Shop& p, Player &real_p);

        int width;
        int height;
        std::deque<std::vector<Block> > mp;
};

int shop(Player & real_p);
#endif
