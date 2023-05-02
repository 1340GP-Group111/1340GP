#include "block.h"
#include "gameMap.h"
#include "io.h"
#include "player.h"
#include "shop.h"
#include "timer.h"
#include "ui.h"
#include<iostream>
#include <unistd.h>
#include <fstream>


int game(Player &p){
	p.setDepth(0);	
	Map mp;
	p.playerInitialization(mp);
    Timer timer;
    timer.start();
//	time_t start_time = time(NULL);// start counting the time
//	time_t end_time = time(NULL);
//	int lasted_time = end_time-start_time;
    ui::draw(mp.mp, p);
//	mp.show_map(p);
	while(true){ //	             MAIN WHILE LOOP OF DIGGING
		int input = ui::listenKeyboard();
		if (input == 'r'){
			return 1;
		}
		if (input == 'a'){
			p.move_left(mp);
		}
		else if(input == 'd'){
			p.move_right(mp);
		}
		else if(input == 's'){
			p.move_down(mp);
		}
		else if(input == 'b'){
			p.bomb(mp);
		}
		
//		end_time = time(NULL); 		//Checking the remaining time for player
//		lasted_time = end_time-start_time;
		p.setTime(p.getOxygen() - timer.getTime());
		if(p.getTime()<0){
			return 3;
		}
        ui::draw(mp.mp, p);
//		mp.show_map(p);
	}
}


int main(){
    srand(time(NULL));
    Player p;
    const int height = 12;    	//	changeable?
    const int width = 20;
    ui::init(height, width); // height, width
    // Main menu.
    int load_result = loadFromFile(p);
    if(load_result == 0){
        ui::printStr("Load data successfully");
    }
    else if(load_result == 1){
        ui::printStr("Welcome to the game!");
    }
    else if(load_result == 2){
        ui::printStr("Failed to load data");
        return 0;
    }
    sleep(2);

    clear();
    ui::drawBorder();
//    sleep(2);
//    endwin();

	int signal = 0; //use to quit the whole game; 0-game 1-Shop 2-Quit 3-Time run out
	while(signal != 2){
		signal = game(p);
		if (signal==1){ //1 -- Switch to Shopping
			signal = shop(p);
		}
		if (signal == 2){ //2 -- Quit the whole game
			break;
		}
		if (signal == 3){
            clear();
            ui::printStr("Time Run Out!");
            ui::printStr("Going into the shop in 2s", 2, 0);
            sleep(2);
			signal = shop(p);
		}
	}

    clear();
	int save_result = saveToFile(p);	// -- Save the data
	if (save_result == 0){
        ui::printStr("Data saved successfully");
	}
	else{
		ui::printStr("Failed to save data");
	}
    endwin();
    return 0;
}
