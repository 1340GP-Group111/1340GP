//
// Created by Cao Rui on 2023/4/7.
//

#ifndef TIMER
#define TIMER

#include <functional>

class Timer{
public:
    Timer();

    // @brief: Start Timer.
    // @param: The time limit.
    void start(int);

    // @brief: Check if the time limit is reached.
    // @return: Return 1 if timeout, 0 otherwise.
    bool chk_timeout();
private:
    static bool timeout_flag;

    // @brief: Wait until reach the time limit in a new thread.
    // @param: Receive the time limit.
    static void wait(int);
};

#endif