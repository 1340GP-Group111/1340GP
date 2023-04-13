#include "block.h"
#include "gameMap.h"
#include "io.h"
#include "player.h"
#include "shop.h"
#include "timer.h"
#include "ui.h"

int shop(Player & real_p){    // Shop ��������
    ShoppingPlayer p(10,5);
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

Player p;

int game(){
    Timer t;
    while(!t.chk_timeout()){
        int key = ui::listenKeyboard();
        // TODO: attack
        if(key == 's'){
            p.move_down();
        }
        else if(key == 'a'){
            p.move_left();
        }
        else if(key == 'd'){
            p.move_right();
        }
        else if(key == 'r'){
            return 1;
        }
        else if(key == 'q'){
            return 2;
        }
    }
}

void gameLoop(){
    // Game loop.
    int signal = 0; //use to quit the whole game;
    while(true){
        signal = game();
        if (signal==1){ //1 -- Switch to Shopping
            signal = shop(p);
        }
        if (signal == 2){ //2 -- Quit the whole game
            return;
        }
    }
}

int main(){
    // Main menu.
    ui::init(Map::HEIGHT, Map::WIDTH);

    return 0;
}