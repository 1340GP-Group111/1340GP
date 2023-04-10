//
// Created by Cao Rui on 2023/4/10.
//

#ifndef SRC_UI_H
#define SRC_UI_H

#include <ncurses.h>

namespace ui{
    // @brief: Init the terminal screen and perform basic settings.
    void init();

    // @brief: Draw the game scene border.
    void drawBorder();

    // @brief: Listen for user keyboard input (no delay).
    // @return: Return the code of the input key, or -1 if no key is caught.
    int listenKeyboard();

}

#endif //SRC_UI_H
