#include "shop.h"
#include <iostream>
#include <algorithm>

void Shop::showShop(Player &player){
    std::vector<char> availableSkins = {'@', '#', '$', '%', '^'}; // available skins. Only some characters now
    std::vector<char> ownedSkins = {'@'}; // owned skins
    std::cout << "Welcome to the shop!" << std::endl; ? // show shop
    std::cout << "You have " << player.getWealth() << " coins." << std::endl; // should add getElement() in player
    std::cout << "1. Buy appearance" << std::endl;
    std::cout << "2. Buy bomb: " << BOMB_PRICE << " coins." << std::endl;
    std::cout << "3. Buy attack: " << ATTACK_PRICE << " coins." << std::endl;
    std::cout << "4. Equip appearance" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << std::endl;
}

void Shop::buyAppearance(Player &player, std::vector<char> &availableSkins, std::vector<char> &ownedSkins){ 
    int option,choice;
    std::cout << "Choose an appearance to buy (enter 0 to exit):" << std::endl;
    // if not own, permitted to buy the skin 
    for(int i=0; i<availableSkins.size(); i++){
        if(std::find(ownedSkins.begin(), ownedSkins.end(), availableSkins[i]) == ownedSkins.end()){ 
            std::cout << i+1 << ". " << availableSkins[i] << " (" << APPEARANCE_PRICE << " coins)" << std::endl;
        }
    }
    std::cin >> option;
    // return to main, showShop again
    if(option == 0){ 
        return;
    }
    // valid selection
    if(option > availableSkins.size()){ 
        std::cout << "Invalid option." << std::endl;
        return;
    }
    char selectedSkin = availableSkins[option-1];
    // if own, player can't buy the appearance
    if(std::find(ownedSkins.begin(), ownedSkins.end(), selectedSkin) != ownedSkins.end()){ 
        std::cout << "You already own this appearance." << std::endl;
        return;
    }
    // if coin is enough
    if(player.getWealth() >= APPEARANCE_PRICE){
        // should add setElement() in player
        player.setWealth(player.getWealth() - APPEARANCE_PRICE); 
        ownedSkins.push_back(selectedSkin);
        std::cout << "You bought an appearance. You now have " << player.getWealth() << " coins." << std::endl;
        // ask if player wants to equip the skin just bought
        std::cout << "Do you wish to equip the skin you just bought? (0 for YES, 1 for NO)" << std::endl;
        std::cin >> choice;
        if(choice==0){
            player.setAppearance(selectedSkin);
            return;
        }
    }else{
        std::cout << "You don't have enough coins." << std::endl;
        return;
    }
}

void Shop::equipAppearance(Player& player, std::vector<char>& ownedSkins) {
    int option;
    std::cout << "Choose an appearance to equip (enter 0 to exit):" << std::endl;
    // list available owned skins
    for (int i = 0; i < ownedSkins.size(); i++) { 
        std::cout << i + 1 << ". " << ownedSkins[i] << std::endl;
    }
    std::cin >> option;
    if (option == 0) {
        return;
    }
    if (option > ownedSkins.size()) {
        std::cout << "Invalid option." << std::endl;
        return;
    }
    char selectedSkin = ownedSkins[option - 1];
    // see if the skins is already equipped
    if (selectedSkin == player.getAppearance()) {
        std::cout << "You already have this appearance equipped." << std::endl;
        return;
    }
    player.setAppearance(selectedSkin);
    std::cout << "You equipped a new appearance." << std::endl;
    return;
}

void Shop::buyBomb(Player &player){
    if(player.getWealth() >= BOMB_PRICE){
        player.setWealth(player.getWealth() - BOMB_PRICE);
        player.setBombNum(player.getBombNum() + 1);
        std::cout << "You bought a bomb. You now have " << player.getBombNum() << " bombs now." << std::endl;
    }else{
        std::cout << "You don't have enough coins." << std::endl;
    }
    return;
}
void Shop::buyAttack(Player &player){
    if(player.getWealth() >= ATTACK_PRICE){
        player.setWealth(player.getWealth() - ATTACK_PRICE);
        // amount of attack added per purchase, undetermind 
        player.setAttack(player.getAttack() + 0);
        std::cout << "You bought an attack. You now have " << player.getAttack() << " attack." << std::endl;
    }else{
        std::cout << "You don't have enough gold coins." << std::endl;
    }
    return;
}

void Shop::buyTime(Player &player, int &time){
    if(player.getWealth() >= TIME_PRICE){
        player.setWealth(player.getWealth() - TIME_PRICE);
        // amount of time added per purchase, undetermind 
        time += 0;
        std::cout << "You bought 0 minutes of time. You now have " << time << " minutes now." << std::endl;
    }else{
        std::cout << "You don't have enough gold coins." << std::endl;
    }
    return;
}

void Shop::exitShop(){
    std::cout << "Thank you for visiting the shop!" << std::endl;
    return;
}
