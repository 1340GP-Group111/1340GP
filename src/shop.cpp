#include "shop.h"
#include <iostream>
#include <algorithm>

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

void Shop::equipAppearance(Player& player) {
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
}

void Shop::buyBomb(Player &player){
    if(player.getWealth() >= BOMB_PRICE){
        player.setWealth(player.getWealth() - BOMB_PRICE);
        player.setBombNum(player.getBombNum() + 1);
        std::cout << "You bought a bomb. You now have " << player.getBombNum() << " bombs now." << std::endl;
        BOMB_PRICE*=10;
    }else{
        std::cout << "You don't have enough coins." << std::endl;
    }
}
void Shop::buyAttack(Player &player){
    if(player.getWealth() >= ATTACK_PRICE){
        player.setWealth(player.getWealth() - ATTACK_PRICE);
        // amount of attack added per purchase, undetermined
        player.setDamage(player.getDamage() + 0);
        std::cout << "You bought an attack. You now have " << player.getDamage() << " attack." << std::endl;
        ATTACK_PRICE*=10;
    }else{
        std::cout << "You don't have enough gold coins." << std::endl;
    }
}

void Shop::buyTime(Player &player, int &time){
    if(player.getWealth() >= TIME_PRICE){
        player.setWealth(player.getWealth() - TIME_PRICE);
        // amount of time added per purchase, undetermined
        time += 0;
        std::cout << "You bought 0 minutes of time. You now have " << time << " minutes now." << std::endl;
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
void Shop::move_up(deque<vector<string> > &mp,Player& real_p){
	if (mp[y-1][x]==" "){
		y--;
	}
	else if(mp[y-1][x] != "#"){
		interact(mp[y-1][x],real_p);
	}
}
void Shop::move_down(deque<vector<string> > &mp,Player& real_p){
	if (mp[y+1][x]==" "){
		y++;
	}
	else if(mp[y+1][x] != "#"){
		interact(mp[y+1][x],real_p);
	}
}
void Shop::move_left(deque<vector<string> > &mp,Player& real_p){
	if (mp[y][x-1]==" "){
		x--;
	}
	else if(mp[y][x-1] != "#"){
		interact(mp[y][x-1],real_p);
	}
}
void Shop::move_right(deque<vector<string> > &mp,Player& real_p){
	if (mp[y][x+1]==" "){
		x++;
	}
	else if(mp[y][x+1] != "#"){
		interact(mp[y][x+1],real_p);
	}
}
void Shop::interact(string tar,Player& real_p){
	if(tar=="L"){
		buyAttack(real_p);
	}
	else if(tar=="M"){
		buyBomb(real_p);
	}
	else if(tar=="A"){
		buyAppearance(real_p);
	}
	else if(tar=="O"){
		buyTime(real_p,5);
	}
	
}

ShoppingMap::ShoppingMap(int width_,int height_){
    width=width_;
    height=height_;
    for(int i=0;i<=height;i++){
        vector<string> temp_line;
        for(int j=0;j<=width;j++){
            string temp=" ";
            temp_line.push_back(temp);
        }
        mp.push_back(temp_line);
    }

    for(deque<vector<string> >::iterator it=mp.begin();it!=mp.end();it++){
        (*it)[0] = "#";
        (*it)[width]="#";					
    }
    for(vector<string>::iterator it = (mp[0]).begin();it!=(mp[0]).end();it++){
        (*it) = "#";
    }
    for(vector<string>::iterator it = mp[height].begin();it!=mp[height].end();it++){
        (*it) = "#";
    }

    mp[height/3][2] = "M";
    mp[height-height/3][2] = "L";
    mp[height/3][width-2] = "A";
    mp[height - height/3][width-2] = "O";
    }
		
void ShoppingMap::show_map(Shop& p, Player &real_p){
    cout<<"\n\n\n\n\n"<<endl;
    int i=0;
    int j=0;
    for(deque<vector<string> >::iterator it=mp.begin();it!=mp.end();it++){
        for(vector<string>::iterator jt = (*it).begin();jt!=(*it).end();jt++){
            if(p.y==i && p.x==j)
                cout<<"P";
            else cout<<(*jt);
            j++;
        }
        if(i==3) cout<<"  Here is the base. You can shop for items or upgrade here.";
        if(i==4) cout<<"  Wealth:"<<real_p.getWealth()<<" Level:"<<real_p.getLevel();
        if(i==5) cout<<"  Type 'r' to start digging";
        if(i==6) cout<<"  Type 'quit' to quit the game";
        j=0;				
        cout<<endl;
        i++;
    }
}

int shop(Player & real_p){     //Main Shopping Loop
	Shop p;
	p.set_xy(10,5);
	ShoppingMap map(20,10);
	map.show_map(p,real_p);
	while(true){
		string Input;
		cin>>Input;
		if(Input=="quit" || Input=="Quit")
			return 2;
		char Input_char=tolower(Input[0]);
		if(Input_char=='w'){
			p.move_up(map.mp,real_p);
		}
		else if(Input_char=='s'){
			p.move_down(map.mp,real_p);
		}
		else if(Input_char=='a'){
			p.move_left(map.mp,real_p);
		}
		else if(Input_char=='d'){
			p.move_right(map.mp,real_p);
		}
		else if(Input_char=='r'){
			return 0;
		}
		
		map.show_map(p,real_p);
		
	}
}
