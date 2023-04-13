// Author: Cao Rui

#include "timer.h"
#include <thread>
#include <future>

Timer::Timer(){
    timeout_flag = false;
}

bool Timer::chk_timeout(){
    return timeout_flag;
}

void Timer::wait(int time_limit){
    timeout_flag = false;
    std::this_thread::sleep_for(std::chrono::seconds(time_limit));
    timeout_flag = true;
}

void Timer::start(int time_limit){  // time limit in second
    std::future<void> fu = std::async(wait, time_limit);
}
