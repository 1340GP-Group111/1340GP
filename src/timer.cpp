// Author: Cao Rui

#include "timer.h"
#include <thread>
#include <future>

Timer::Timer(){}

bool Timer::timeout(){          // Check if the time limit is reached
    return timeout_flag;
}

void Timer::wait(int time_limit){       //  Wait to reach the time limit in the new thread.
    timeout_flag = false;
    std::this_thread::sleep_for(std::chrono::seconds(time_limit));
    timeout_flag = true;
}

void Timer::start(int time_limit){  // time limit in second
    std::future<void> fu = std::async(wait, time_limit);        // Start a new thread to count down
}
