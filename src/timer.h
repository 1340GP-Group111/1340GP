//
// Created by Cao Rui on 2023/4/7.
//

#ifndef TIMER
#define TIMER

class Timer{
public:
    Timer();
    // @brief: Start Timer.
    // @param: The time limit.
    void start();

    // @brief: Get the time elapsed since the timer started.
    // @return: The time elapsed in second.
    int getTime() const;

    //discarded
    // @brief: Check if the time limit is reached.
    // @return: Return 1 if timeout, 0 otherwise.
//    bool chk_timeout() const;
private:
    clock_t start_time;
};

#endif