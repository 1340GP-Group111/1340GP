#ifndef SHOP_H
#define SHOP_H

#include "player.h"
#include <vector>

class Shop {
    private:
        std::vector<char> availableSkins;
        std::vector<char> ownedSkins;
        static const int APPEARANCE_PRICE = 0; // appearance price
        static const int BOMB_PRICE = 0; // bomb price
        static const int ATTACK_PRICE = 0; // attack price
        static const int TIME_PRICE = 0; // time price, time is priceless lol, time is gold!
    public:
        void showShop(Player &player);
        void buyAppearance(Player &player);
        void equipAppearance(Player &player);
        void buyBomb(Player &player);
        void buyAttack(Player &player);
        void buyTime(Player &player);
        void exitShop();
};

#endif
