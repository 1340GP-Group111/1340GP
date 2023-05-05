//custom header file
#include "block.h"
#include "gameMap.h"
#include "io.h"
#include "player.h"
#include "shop.h"
#include "timer.h"
#include "ui.h"

//std library
#include<iostream>
#include <fstream>

//POSIX--unix std library
#include <unistd.h>

int game(Player &p);

int main(){
    //Initialize the random seed
    srand(time(NULL));
    Player p;                   //define a player

    const int height = 12;    	//gameMap height
    const int width = 20;       //gameMap width

    //Initialize the UI
    ui::init(height, width);    //height, width


    //Main menu

    //New game or Load the game
    int load_result = loadFromFile(p);
    if(load_result == 0){         //Load successfully
        ui::printStr("Load data successfully");
    }
    else if(load_result == 1){    //New game
        ui::printStr("Welcome to the game!");
    }
    else if(load_result == 2){    //failed to load--data invalid
        ui::printStr("Failed to load data");
        return 0;
    }

    sleep(2);

    clear();
    ui::drawBorder();  //draw gameMap


    int signal = 0;        //use to quit the whole game; 0-game 1-Shop 2-Quit 3-Time run out

    while(signal != 2){

        signal = game(p);    //start game

        if (signal==1){      //1 -- Switch to Shopping
            signal = shop(p);
        }
        if (signal == 2){    //2 -- Quit the whole game
            break;
        }
        if (signal == 3){    //Time run out

            clear();
            ui::printStr("Time Run Out!",16,1);
            ui::printStr("Going into the shop in 2s", 17, 1);
            sleep(2);        //wait 2s

            //Clear the text in the interface
            ui::printStr("                  ",16,1);
            ui::printStr("                                ", 17, 1);

            signal = shop(p); //Switch to Shopping

        }
    }

    clear();                                    //clear all output
    int save_result = saveToFile(p);	        //Save the data
    if (save_result == 0){
        ui::printStr("Data saved successfully");//saved successfully
    }
    else{
        ui::printStr("Failed to save data");    //saved Failed
    }

    endwin();  //end the game

    return 0;
}

int game(Player &p){
    //Game Initialization
    p.setDepth(0);  //new game set depth to 0
    Map mp;         //define game map

    //player Initialization
    p.playerInitialization(mp);

    //set timer
    //Timer timer
    //timer.start()
    time_t start_time = time(NULL);// start counting the time
    time_t end_time = time(NULL);
    int lasted_time = end_time-start_time;

    ui::draw(mp.mp, p);        //draw gameMap
    
    
    while(true){               //MAIN WHILE LOOP OF DIGGING

        //non-blocking listener
        int input = ui::listenKeyboard();

        //Actions available in the game
        if (input == 'r'){      //Switch to Shopping
            return 1;
        }
        if (input == 'a'){      //player move left
            p.move_left(mp);
        }
        else if(input == 'd'){  //player move right
            p.move_right(mp);
        }
        else if(input == 's'){  //player move down
            p.move_down(mp);
        }
        else if(input == 'b'){  //player use bomb
            p.bomb(mp);
        }

        end_time = time(NULL); 		//Checking the remaining time for player
        lasted_time = end_time-start_time;
        p.setTime(p.getOxygen() - lasted_time);
        if(p.getTime()<0){
            return 3;
        }

        ui::draw(mp.mp, p);//draw gamemap

        //mp.show_map(p);
    }
}
