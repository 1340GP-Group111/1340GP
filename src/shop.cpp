#include "shop.h"
#include "ui.h"
#include "block.h"
#include <iostream>
#include <algorithm>
#include <curses.h>
Shop::Shop(){
    availableSkins = {'@', '#', '$', '%', '^'}; // available skins. Only some characters now. We can have "☺","☹","♚","☃","☠"
    ownedSkins = {'@'}; // owned skins
    APPEARANCE_PRICE = 0; // appearance price
    BOMB_PRICE = 0; // bomb price
    ATTACK_PRICE = 0; // attack price
    TIME_PRICE = 0;// time price, time is priceless lol, time is gold!
}

void Shop::showShop(Player &player) const{
    std::cout << "Welcome to the shop!" << std::endl; // show shop
    std::cout << "You have " << player.getWealth() << " coins." << std::endl; // should add getElement() in player
    std::cout << "1. Buy appearance" << std::endl;
    std::cout << "2. Buy bomb: " << BOMB_PRICE << " coins." << std::endl;
    std::cout << "3. Buy attack: " << ATTACK_PRICE << " coins." << std::endl;
    std::cout << "4. Equip appearance" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << std::endl;
}

void Shop::buyAppearance(Player &player){
    int option,choice;
    std::cout << "Choose an appearance to buy (enter 0 to exit):" << std::endl;
    // if not own, permitted to buy the skin 
    for(int i=0; i<availableSkins.size(); i++){
        if(std::find(ownedSkins.begin(), ownedSkins.end(), availableSkins[i]) == ownedSkins.end()){ 
            std::cout << i+1 << ". " << availableSkins[i] << " (" << APPEARANCE_PRICE << " coins)" << std::endl;
        }
    }

    // return to main, showShop again
    while (true){
        std::cout << "Please input corresponding numeral (enter 0 to exit):" << std::endl;
        while(true){
            std::in>>option;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input: Input must be an integer." << std::endl;
            } else {
                std::cin.ignore(10000, '\n');
                break;
            }
        }

        if(option == 0){
            break;
        }

        if(option > availableSkins.size()){
            std::cout << "Invalid option: Input exceeds appearance number." << std::endl;
            continue;
        }

        char selectedSkin = availableSkins[option-1];
        // if own, player can't buy the appearance
        if(std::find(ownedSkins.begin(), ownedSkins.end(), selectedSkin) != ownedSkins.end()){
            std::cout << "You already own this appearance." << std::endl;
            continue;
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
            }
        }else{
            std::cout << "You don't have enough coins." << std::endl;
        }
    }

}

void Shop::equipAppearance(Player& player) {
    int option;
    std::cout << "Choose an appearance to equip (enter 0 to exit):" << std::endl;
    // list available owned skins
    for (int i = 0; i < ownedSkins.size(); i++) {
        std::cout << i + 1 << ". " << ownedSkins[i] << std::endl;
    }

    while (true){
        std::cout << "Please input corresponding numeral (enter 0 to exit):" << std::endl;
        while(true){
            std::cin >> option;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input: Input must be an integer." << std::endl;
            } else {
                std::cin.ignore(10000, '\n');
                break;
            }
        }

        if(option == 0){
            break;
        }

        if(option > ownedSkins.size()){
            std::cout << "Invalid option: Input exceeds appearance number." << std::endl;
            continue;
        }

        if (option > ownedSkins.size()) {
            std::cout << "Invalid option." << std::endl;
            continue;
        }
        char selectedSkin = ownedSkins[option - 1];
        // see if the skins is already equipped
        if (selectedSkin == player.getAppearance()) {
            std::cout << "You already have this appearance equipped." << std::endl;
            continue;
        }
        player.setAppearance(selectedSkin);
        std::cout << "You equipped a new appearance." << std::endl;
    }
}




void Shop::buyBomb(Player &player){
    if(player.getWealth() >= BOMB_PRICE){
        player.setWealth(player.getWealth() - BOMB_PRICE);
        player.setBombNum(player.getBombNum() + 1);
        std::cout <<"\n"<<"You bought a bomb. You now have " << player.getBombNum() << " bombs now." << std::endl;
        BOMB_PRICE*=10;
    }else{
        std::cout <<"\n"<< "You don't have enough coins." << std::endl;
    }
}
void Shop::buyAttack(Player &player){
    if(player.getWealth() >= ATTACK_PRICE){
        player.setWealth(player.getWealth() - ATTACK_PRICE);
        // amount of attack added per purchase, undetermined
        player.setDamage(player.getDamage() + 0);
        std::cout <<"\n"<< "You bought an attack. You now have " << player.getDamage() << " attack." << std::endl;
        ATTACK_PRICE*=10;
    }else{
        std::cout <<"\n"<< "You don't have enough gold coins." << std::endl;
    }
}

void Shop::buyTime(Player &player, int time){
    if(player.getWealth() >= TIME_PRICE){
        player.setWealth(player.getWealth() - TIME_PRICE);
        // amount of time added per purchase, undetermined
        player.setOxygen( player.getOxygen() + time );
        std::cout <<"\n"<< "You bought 0 minutes of time. You now have " << player.getOxygen() << " minutes now." << std::endl;
        TIME_PRICE*=10;
    }else{
        std::cout << "You don't have enough gold coins." << std::endl;
    }
}

void Shop::exitShop(){
    std::cout << "Thank you for visiting the shop!" << std::endl;
}


void Shop::set_xy(int x_,int y_){
	x=x_;
	y=y_;
}
void Shop::move_up(std::deque<std::vector<Block> > &mp,Player& real_p){
	Block &target=mp[y-1][x];
	if (target.get_status()==0){
		y--;
	}
	else if(target.get_status() != 3){
		interact(mp[y-1][x],real_p);
	}
}
void Shop::move_down(std::deque<std::vector<Block> > &mp,Player& real_p){
	Block &target=mp[y+1][x];
	if (target.get_status()==0){
		y++;
	}
	else if(target.get_status() != 3){
		interact(mp[y+1][x],real_p);
	}
}
void Shop::move_left(std::deque<std::vector<Block> > &mp,Player& real_p){
	Block &target=mp[y][x-1];
	if (target.get_status()==0){
		x--;
	}
	else if(target.get_status() != 3){
		interact(mp[y][x-1],real_p);
	}
}
void Shop::move_right(std::deque<std::vector<Block> > &mp,Player& real_p){
	Block &target=mp[y][x+1];
	if (target.get_status()==0){
		x++;
	}
	else if(target.get_status() != 3){
		interact(mp[y][x+1],real_p);
	}
}
void Shop::interact(const Block& tar,Player& real_p){
	if(tar.get_status()==5){
		buyAttack(real_p);
	}
	else if(tar.get_status()==4){
		buyBomb(real_p);
	}
	else if(tar.get_status()==6){
		buyAppearance(real_p);
	}
	else if(tar.get_status()==7){
		buyTime(real_p,5);
	}
	
}

ShoppingMap::ShoppingMap(int width_,int height_){
    width=width_;
    height=height_;
    for(int i=0;i<=height;i++){
        std::vector<Block> temp_line;
        for(int j=0;j<=width;j++){
            Block temp= space;
            temp_line.push_back(temp);
        }
        mp.push_back(temp_line);
    }
    Block a = ob_0;
    for(auto & it : mp){
        it[0] = a;
        it[width-1]= a;
    }
    for(auto & it : mp[0]){
        it = a;
    }
    for(auto & it : mp[height]){
        it = a;
    }
    Block m=MM;
    Block l=ML;
    Block A=MA;
    Block O=MO;
    mp[height/3][2] = MM;
    mp[height-height/3][2] = ML;
    mp[height/3][width-3] = MA;
    mp[height - height/3][width-3] = MO;
    }
		
void ShoppingMap::show_map(Shop& p, Player &real_p){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            char ch;
            std::string id;
            if(!mp[i][j].get_status()){             // There is no block.
                ch = ' ';
                id = "blank";
            }
            else{
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

    ui::printStr("Current depth: "+std::to_string(real_p.getDepth()), 3, width+5, "white");
    ui::printStr("Wealth: "+std::to_string(real_p.getWealth())+"\t\tLevel: "+std::to_string(real_p.getLevel()), 4, width+5, "white");
    ui::printStr("Bomb: "+std::to_string(real_p.getBombNum())+"\t\tOxygen Pack: "+std::to_string(real_p.getOxygen()), 5, width+5, "white");
    ui::printStr("Use a,s,d to move, b to use a bomb", 7, width+5, "white");
    ui::printStr("Press 'r' to go back to the base", 8, width+5, "white");
    refresh();
}

int shop(Player & real_p){     //Main Shopping Loop
	Shop p;
	p.set_xy(10,5);
	ShoppingMap map(20,10);
	map.show_map(p,real_p);
	while(true){
		int input_char = getch();
		if(input_char == 'q'){
			return 2;
		}
		if(input_char == 'w'){
			p.move_up(map.mp,real_p);
		}
		else if(input_char == 's'){
			p.move_down(map.mp,real_p);
		}
		else if(input_char == 'a'){
			p.move_left(map.mp,real_p);
		}
		else if(input_char == 'd'){
			p.move_right(map.mp,real_p);
		}
		else if(input_char == 'r'){
			return 0;
		}
		
		map.show_map(p,real_p);
		
	}
}
