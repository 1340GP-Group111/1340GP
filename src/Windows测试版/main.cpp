#include "block.h"
#include "gameMap.h"
#include "io.h"
#include "player.h"
#include "shop.h"
//#include "timer.h"
//#include "ui.h"
#include<conio.h> // to be deleted
#include<iostream>
#include<ctime>

Player p;

int Game(Player &p){
	p.setDepth(0);
	p.setAppearance('P');	
	Map mp;
	p.playerInitialization(mp);
	time_t start_time = time(NULL);// start counting the time
	time_t end_time = time(NULL);
	int lasted_time = end_time-start_time;
	mp.show_map(p);
	while(true){ //	             MAIN WHILE LOOP OF DIGGING
		char Input;
		Input = getch();
		if (Input == 'r'){
			return 1;
		}
		
		Input = tolower(Input);
		if (Input=='a'){
			p.move_left(mp);
		}
		else if(Input=='d'){
			p.move_right(mp);
		}
		else if(Input=='s'){
			p.move_down(mp);
		}
		else if(Input=='b'){
			p.bomb(mp);
		}
		
		end_time = time(NULL); 		//Checking the remaining time for player
		lasted_time = end_time-start_time;
		p.setTime(p.getOxygen() - lasted_time);
		mp.show_map(p);
		if(p.getTime()<0){
			return 3;
		}
	}
}
int main(){
    // Main menu.
    int load_result = loadFromFile(p);
	if(load_result == 0){
		std::cout<<"\n\nLoad data successfully"<<std::endl;
	}
	else{
		std::cout<<"\n\nFailed to load data"<<std::endl;
	}
    int height = 20;    	//	changeable?
    int width = 12;
//    ui::init(height, width);
	
	int signal = 0; //use to quit the whole game; 0-Game 1-Shop 2-Quit 3-Time run out
	while(signal != 2){
		signal = Game(p);
		if (signal==1){ //1 -- Switch to Shopping
			signal = shop(p);
		}
		if (signal == 2){ //2 -- Quit the whole game
			break;
		}
		if (signal == 3){
			std::cout<<"\n\n  Time Run Out! \n\n Type anything to continue \n"<<std::endl;
			std::string temp;
			std::cin>>temp;
			signal = shop(p);
		}
	}
	
	int save_result = saveToFile(p);	// -- Save the data
	if (save_result == 0){
		std::cout<<"Data saved successfully\n\n"<<std::endl;
	}
	else{
		std::cout<<"Failed to save data\n\n"<<std::endl;
	}
    return 0;
}
