//
// Created by Cao Rui on 2023/4/10.
//

#ifndef SRC_UI_H
#define SRC_UI_H

#include <ncurses.h>
#include <unordered_map>
#include <string>
#include <deque>
#include <vector>
#include "player.h"
#include "block.h"

namespace ui{
    static int height, width;
    static std::unordered_map<std::string, int> color_id;

    // @brief: Init the terminal screen and perform basic settings.
    // @param: The height and the width of the game window.
    void init(int, int);

    // @brief: Listen for user keyboard input (no delay).
    // @return: Return the code of the input key, or -1 if no key is caught.
    int listenKeyboard();

    // @brief: Print a string on the screen.
    // @param: The position of the string; The string; The color of the string.
    void printStr(const std::string&, int = 0, int = 0, const std::string& = "white");

    // @brief: Draw the game scene border.
    void drawBorder();

    // @brirf: Draw the game map and the player.
    // @param: game map (by ref); Player (by ref).
    void draw(const std::deque<std::vector<Block>>&, const Player&);
}

#endif //SRC_UI_H
