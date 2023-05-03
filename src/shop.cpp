#include "shop.h"
#include "ui.h"
#include "block.h"
#include <iostream>
#include <algorithm>
#include <curses.h>
#include <cmath>

Shop::Shop(){
    availableSkins = {'@', '$', '$', '%',
                      '^'}; // available skins. Only some characters now. We can have "☺","☹","♚","☃","☠"
    ownedSkins = {'@'}; // owned skins
    APPEARANCE_PRICE = 1000; // appearance price
    BOMB_PRICE = 50; // bomb price
    ATTACK_PRICE = 500; // attack price
    TIME_PRICE = 200;// time price, time is priceless lol, time is gold!
}

void Shop::showShop(Player &player) const{
    std::cout<<"Welcome to the shop!"<<std::endl; // show shop
    std::cout<<"You have "<<player.getWealth()<<" coins."<<std::endl; // should add getElement() in player
    std::cout<<"1. Buy appearance"<<std::endl;
    std::cout<<"2. Buy bomb: "<<BOMB_PRICE<<" coins."<<std::endl;
    std::cout<<"3. Buy attack: "<<ATTACK_PRICE<<" coins."<<std::endl;
    std::cout<<"4. Equip appearance"<<std::endl;
    std::cout<<"5. Exit"<<std::endl;
    std::cout<<std::endl;
}

void Shop::buyAppearance(Player &player){
    char option, choice;
    ui::printStr("Choose an appearance to change (enter 0 to exit):", 16, 1, "white");
    // if not own, permitted to buy the skin 
    for(int i = 0; i < availableSkins.size(); i++){

        //std::cout << i+1 << ". " << availableSkins[i] << " (" << APPEARANCE_PRICE << " coins)" << std::endl;
        ui::printStr(std::to_string(i+1)+". "+availableSkins[i]+" ("+std::to_string(APPEARANCE_PRICE)+" coins)", 16+i+1,
                     1, "white");

    }

    // return to main, showShop again
    while(true){
        //std::cout << "Please input corresponding numeral (enter 0 to exit):" << std::endl;
        ui::printStr("Please input corresponding numeral (enter 0 to exit):", 16+availableSkins.size()+1, 1, "white");
        while(true){
            ui::printStr("                                                 ", 16+availableSkins.size()+1, 1, "white");
            option = getch();
//             if(std::cin.fail()){
//                 std::cin.clear();
//                 std::cin.ignore(10000, '\n');
//                 std::cout << "Invalid input: Input must be an integer." << std::endl;
//             } else {
//                 std::cin.ignore(10000, '\n');
//                 break;
//             }
            if('0' <= option && '9' >= option){
                break;
            } else{
                ui::printStr("Invalid input: Input must be an integer.", 16+availableSkins.size()+1, 1, "white");
            }
        }

        if(option == '0'){
            for(int i = 16; i < 26; i++){
                ui::printStr("                                                        ", i, 1, "white");
            }
            break;
        }

        int int_option = option-48; // Char -> Int
        if(int_option > availableSkins.size()){
            ui::printStr("Invalid option: Input exceeds appearance number.", 16+availableSkins.size()+2, 1, "white");
            continue;
        }

        char selectedSkin = availableSkins[int_option-1];
        // if own, player can't buy the appearance
        // if coin is enough
        if(player.getWealth() >= APPEARANCE_PRICE){
            // should add setElement() in player
            player.setWealth(player.getWealth()-APPEARANCE_PRICE);
            //std::cout << "You bought an appearance. You now have " << player.getWealth() << " coins." << std::endl;
            ui::printStr("You bought an appearance. You now have "+std::to_string(player.getWealth())+" coins.",
                         16+availableSkins.size()+3, 1, "white");
            // ask if player wants to equip the skin just bought
            player.setAppearance(selectedSkin);

        } else{
            ui::printStr("You don't have enough coins. (enter 0 to exit)", 16+availableSkins.size()+3, 1, "white");
        }
    }

}

void Shop::equipAppearance(Player &player){
    char option;
    ui::printStr("Choose an appearance to equip (enter 0 to exit):", 16, 1, "white");
    // list available owned skins
    for(int i = 0; i < ownedSkins.size(); i++){
        //std::cout << i + 1 << ". " << ownedSkins[i] << std::endl;
        ui::printStr(std::to_string(i+1)+". "+ownedSkins[i], 16+i+1, 1, "white");
    }

    while(true){
        ui::printStr("Please input corresponding numeral (enter 0 to exit):", 16+ownedSkins.size()+1, 1, "white");
        while(true){
//             std::cin >> option;
//             if(std::cin.fail()){
//                 std::cin.clear();
//                 std::cin.ignore(10000, '\n');
//                 std::cout << "Invalid input: Input must be an integer." << std::endl;
//             } else {
//                 std::cin.ignore(10000, '\n');
//                 break;
//             }
            option = getch();
            if(option <= '9' && option >= '0'){
                break;
            } else{
                ui::printStr("Invalid input: Input must be an integer.", 16+ownedSkins.size()+2, 1, "white");
            }
        }

        if(option == '0'){
            break;
        }
        int int_option = option-48;
        if(int_option > ownedSkins.size()){
            ui::printStr("Invalid option: Input exceeds appearance number.", 16+ownedSkins.size()+3, 1, "white");
            continue;
        }

        char selectedSkin = ownedSkins[int_option-1];
        // see if the skins is already equipped
        if(selectedSkin == player.getAppearance()){
            ui::printStr("You already have this appearance equipped. (Enter 0 to exit)", 16+ownedSkins.size()+3, 1,
                         "white");
            continue;
        }
        player.setAppearance(selectedSkin);
        ui::printStr("You equipped a new appearance.", 16+ownedSkins.size()+4, 1, "white");
    }
}


void Shop::buyBomb(Player &player){
    if(player.getWealth() >= BOMB_PRICE){
        player.setWealth(player.getWealth()-BOMB_PRICE);
        player.setBombNum(player.getBombNum()+1);
        //std::cout <<"\n"<<"You bought a bomb. You now have " << player.getBombNum() << " bombs now." << std::endl;
        ui::printStr("You bought a bomb. You now have "+std::to_string(player.getBombNum())+" bombs now.", 16, 1,
                     "white");
    } else{
        ui::printStr("You don't have enough coins. (Price: 50 coins)", 16, 1, "white");
    }
}

void Shop::buyAttack(Player &player){
    int price_a = ATTACK_PRICE*pow(3, player.getDamage()-1);
    if(player.getWealth() >= ATTACK_PRICE*pow(3, player.getDamage()-1)){
        player.setWealth(player.getWealth()-ATTACK_PRICE*pow(3, player.getDamage()-1));
        // amount of attack added per purchase, undetermined
        player.setDamage(player.getDamage()+1);
        //std::cout <<"\n"<< "You bought an attack. You now have " << player.getDamage() << " attack." << std::endl;
        ui::printStr("You bought an attack. You now have "+std::to_string(player.getDamage())+" attack.", 16, 1,
                     "white");

    } else{
        ui::printStr("You don't have enough gold coins. (Price: "+std::to_string(price_a)+" coins)", 16, 1, "white");
    }
}

void Shop::buyTime(Player &player, int time){
    int price_o = TIME_PRICE*pow(2, player.getOxygen()/5-2);
    if(player.getWealth() >= TIME_PRICE*pow(2, player.getOxygen()/5-2)){
        player.setWealth(player.getWealth()-TIME_PRICE*pow(2, player.getOxygen()/5-2));
        // amount of time added per purchase, undetermined
        player.setOxygen(player.getOxygen()+time);
        //std::cout <<"\n"<< "You bought 0 minutes of time. You now have " << player.getOxygen() << " minutes now." << std::endl;
        ui::printStr("You bought"+std::to_string(time)+"units of oxygen. Your oxygen pack is "+
                     std::to_string(player.getOxygen())+" now.", 16, 1, "white");
    } else{
        ui::printStr("You don't have enough gold coins. (Price: "+std::to_string(price_o)+" coins)", 16, 1, "white");
    }
}

void Shop::exitShop(){
    ui::printStr("Thank you for visiting the shop!", 16, 1, "white");
}


void Shop::set_xy(int x_, int y_){
    x = x_;
    y = y_;
}

void Shop::move_up(std::deque<std::vector<Block> > &mp, Player &real_p){
    Block &target = mp[y-1][x];
    if(target.get_status() == 0){
        y--;
    } else if(target.get_status() != 3){
        interact(mp[y-1][x], real_p);
    }
}

void Shop::move_down(std::deque<std::vector<Block> > &mp, Player &real_p){
    Block &target = mp[y+1][x];
    if(target.get_status() == 0){
        y++;
    } else if(target.get_status() != 3){
        interact(mp[y+1][x], real_p);
    }
}

void Shop::move_left(std::deque<std::vector<Block> > &mp, Player &real_p){
    Block &target = mp[y][x-1];
    if(target.get_status() == 0){
        x--;
    } else if(target.get_status() != 3){
        interact(mp[y][x-1], real_p);
    }
}

void Shop::move_right(std::deque<std::vector<Block> > &mp, Player &real_p){
    Block &target = mp[y][x+1];
    if(target.get_status() == 0){
        x++;
    } else if(target.get_status() != 3){
        interact(mp[y][x+1], real_p);
    }
}

void Shop::interact(const Block &tar, Player &real_p){
    if(tar.get_status() == 5){
        buyAttack(real_p);
    } else if(tar.get_status() == 4){
        buyBomb(real_p);
    } else if(tar.get_status() == 6){
        buyAppearance(real_p);
    } else if(tar.get_status() == 7){
        buyTime(real_p, 5);
    }

}

ShoppingMap::ShoppingMap(int width_, int height_){
    width = width_;
    height = height_;
    for(int i = 0; i <= height; i++){
        std::vector<Block> temp_line;
        for(int j = 0; j <= width; j++){
            Block temp = space;
            temp_line.push_back(temp);
        }
        mp.push_back(temp_line);
    }
    Block a = ob_0;
    for(auto &it: mp){
        it[0] = a;
        it[width-1] = a;
    }
    for(auto &it: mp[0]){
        it = a;
    }
    for(auto &it: mp[height-1]){
        it = a;
    }
    Block m = MM;
    Block l = ML;
    Block A = MA;
    Block O = MO;
    mp[height/3][2] = MM;
    mp[height-height/3][2] = ML;
    mp[height/3][width-3] = MA;
    mp[height-height/3][width-3] = MO;
}

void ShoppingMap::show_map(Shop &p, Player &real_p){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            char ch;
            std::string id;
            if(!mp[i][j].get_status()){             // There is no block.
                ch = ' ';
                id = "blank";
            } else{
                ch = mp[i][j].get_appearance();
                id = mp[i][j].get_id();
            }
            int color = ui::color_id[id];
            attron(COLOR_PAIR(color));
            mvaddch(i+1, j+1, ch);
            attroff(COLOR_PAIR(color));
        }
    }
    int y = p.y, x = p.x;
    mvaddch(y+1, x+1, real_p.getAppearance());

    ui::printStr("Wealth: "+std::to_string(real_p.getWealth())+"\t\tDamage: "+std::to_string(real_p.getDamage()), 2,
                 width+5, "white");
    ui::printStr("Bomb: "+std::to_string(real_p.getBombNum())+"\t\tOxygen Pack: "+std::to_string(real_p.getOxygen()), 3,
                 width+5, "white");
    ui::printStr("Talk with 'L' to upgrade your Damage", 4, width+5, "white");
    ui::printStr("Talk with 'M' to buy bombs", 5, width+5, "white");
    ui::printStr("Talk with 'A' to buy new skins ", 6, width+5, "white");
    ui::printStr("Talk with 'O' to expand your oxygen pack", 7, width+5, "white");
    ui::printStr("Press 'r' to restart the game", 8, width+5, "yellow");
    ui::printStr("Press 'q' to quit the game", 9, width+5, "yellow");
    refresh();
}

int shop(Player &real_p){
    ui::drawBorder();
//Main Shopping Loo
    Shop p;
    p.set_xy(10, 5);
    ShoppingMap map(20, 12);
    map.show_map(p, real_p);
    while(true){
        int input_char = getch();
        if(input_char == 'q'){
            return 2;
        }
        if(input_char == 'w'){
            p.move_up(map.mp, real_p);
        } else if(input_char == 's'){
            p.move_down(map.mp, real_p);
        } else if(input_char == 'a'){
            p.move_left(map.mp, real_p);
        } else if(input_char == 'd'){
            p.move_right(map.mp, real_p);
        } else if(input_char == 'r'){
            ui::printStr("                                                 ", 2, 25, "white");
            ui::printStr("                                                 ", 6, 25, "white");
            ui::printStr("                                         ", 9, 25, "white");
            return 0;
        }

        map.show_map(p, real_p);

    }
}

