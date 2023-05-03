//
// Created by Cao Rui on 2023/4/10.
//

#include <ncurses.h>
#include <fstream>
#include "ui.h"

void ui::init(int height_, int width_){
    height = height_, width = width_;
    initscr();
    cbreak();           // Turn off input buffer. Read every input character immediately.
    noecho();           // Turn off input echo.
    curs_set(0);        // Hide the cursor.
    timeout(200);       // Set timeout for getch() to 200ms.
    clear();

    // Color settings
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);             color_id["white"] = 1;
    init_pair(2, COLOR_GREEN, COLOR_BLACK);             color_id["green"] = 2;
    init_pair(3, COLOR_BLUE, COLOR_BLACK);              color_id["blue"] = 3;
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);            color_id["yellow"] = 4;
    init_pair(5, COLOR_RED, COLOR_BLACK);               color_id["red"] = 5;
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);           color_id["pink"] = 6;
    init_pair(7, COLOR_CYAN, COLOR_BLACK);              color_id["cyan"] = 7;
    init_pair(8, COLOR_BLACK, COLOR_BLACK);             color_id["blank"] = 8;
    init_pair(9, COLOR_CYAN, COLOR_CYAN);
}


int ui::listenKeyboard(){
    int key = getch();
    if(key < 'a' || key > 'z') return 0;
    return key;
}

void ui::printStr(const std::string& str, const int y, const int x, const std::string& color){
    int num = ui::color_id[color];
    attron(COLOR_PAIR(num));
    mvaddstr(y, x, "                                                                                 ");
    mvaddstr(y, x, str.c_str());
    attroff(COLOR_PAIR(num));
    refresh();
}

void ui::drawBorder(){
    attron(COLOR_PAIR(9));                      // Set border color
    for(int i = 0; i <= height+1; i++){         // left and right border.
        mvaddch(i, 0, ' ');
        mvaddch(i, width+1, ' ');
    }
    for(int i = 0; i <= width+1; i++){          // up and down border
        mvaddch(0, i, ' ');
        mvaddch(height+1, i, ' ');
    }
    attroff(COLOR_PAIR(9));
    refresh();
}

void ui::draw(const std::deque<std::vector<Block>>& mp, const Player& player){

//    fout << mp.size() << " " << mp[0].size() << std::endl;
//    fout << height << " " << width << std::endl;
//    endwin();
//    exit(0);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            char ch;
            std::string id;
//            fout << i << " " << j << std::endl;
            if(!mp[i][j].get_status()){             // There is no block.
                ch = ' ';
                id = "blank";
            }
            else{
                ch = mp[i][j].get_appearance();
                id = mp[i][j].get_id();
            }
            int color = color_id[id];
            attron(COLOR_PAIR(color));
            mvaddch(i+1, j+1, ch);
            attroff(COLOR_PAIR(color));
        }
    }
    int y = height/2, x = player.getX();
    mvaddch(y+1, x+1, player.getAppearance());

    ui::printStr("Current depth: "+std::to_string(player.getDepth()), 3, width+5, "white");
    ui::printStr("Wealth: "+std::to_string(player.getWealth())+"\t\tDamage: "+std::to_string(player.getDamage()), 4, width+5, "white");
    ui::printStr("Bomb: "+std::to_string(player.getBombNum())+"\t\tOxygen Pack: "+std::to_string(player.getTime())+"/"+std::to_string(player.getOxygen()), 5, width+5, "white");
    ui::printStr("Use a,s,d to move, b to use a bomb", 7, width+5, "white");
    ui::printStr("Press 'r' to go back to the base", 8, width+5, "white");
    refresh();
}
