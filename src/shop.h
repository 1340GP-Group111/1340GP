#ifndef SHOP_H
#define SHOP_H

#include "player.h"
#include <vector>

class Shop {
    private:
        std::vector<char> availableSkins;
        std::vector<char> ownedSkins;
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
        void buyTime(Player &player, int &time);
        static void exitShop();
};

#endif