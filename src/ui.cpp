//
// Created by Cao Rui on 2023/4/10.
//

#include "ui.h"

void ui::init(int height_, int width_){
    height = height_, width = width_;
    initscr();
    cbreak();           // Turn off input buffer. Read every input character immediately.
    noecho();           // Turn off input echo.
    curs_set(0);        // Hide the cursor.
    nodelay(stdscr, true);     // Set getch() to nodelay mode. Avoid blocking the main loop;
    clear();

    // Color settings
    start_color();
    init_pair(0, COLOR_CYAN, COLOR_CYAN);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);             color_id["white"] = 1;
    init_pair(2, COLOR_GREEN, COLOR_BLACK);             color_id["green"] = 2;
    init_pair(3, COLOR_BLUE, COLOR_BLACK);              color_id["blue"] = 3;
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);            color_id["yellow"] = 4;
    init_pair(5, COLOR_RED, COLOR_BLACK);               color_id["red"] = 5;
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);           color_id["pink"] = 6;
    init_pair(7, COLOR_CYAN, COLOR_BLACK);              color_id["cyan"] = 7;
    init_pair(8, COLOR_BLACK, COLOR_BLACK);             color_id["blank"] = 8;
}

int ui::listenKeyboard(){
    int key = getch();
    if(key == ERR) return -1;
    return key;
}

void ui::drawBorder(){
    attron(COLOR_PAIR(1));                      // Set border color
    for(int i = 0; i <= height+1; i++){         // left and right border.
        mvaddch(i, 0, ' ');
        mvaddch(i, width+1, ' ');
    }
    for(int i = 0; i <= width+1; i++){          // up and down border
        mvaddch(0, i, ' ');
        mvaddch(height+1, i, ' ');
    }
    attroff(COLOR_PAIR(1));
    refresh();
}

void ui::draw(const std::deque<std::vector<Block>>& mp, const Player& player){
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
            int color = color_id[id];
            attron(COLOR_PAIR(color));
            mvaddch(i+1, j+1, ch);
            attroff(COLOR_PAIR(color));
        }
    }
    int y = height/2, x = player.getX();
    mvaddch(y+1, x+1, player.getAppearance());
    refresh();
}