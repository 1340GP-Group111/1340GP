//
// Created by Cao Rui on 2023/4/10.
//

#include "ui.h"

void ui::init(){
    initscr();
    cbreak();           // Turn off input buffer. Read every input character immediately.
    noecho();           // Turn off input echo.
    curs_set(0);        // Hide the cursor.
    nodelay(stdscr, true);     // Set getch() to nodelay mode. Avoid blocking the main loop;
}


void ui::drawBorder(){

}

int ui::listenKeyboard(){
    int key = getch();
    if(key == ERR) return -1;
    return key;
}

