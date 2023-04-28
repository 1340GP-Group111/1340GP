// Author: Cao Rui

#include <ctime>
#include "timer.h"

Timer::Timer(){
    start_time = 0;
}

void Timer::start(){  // time limit in second
    start_time = clock();
}

int Timer::getTime() const{
    return (int)((long long)(clock() - start_time) / CLOCKS_PER_SEC);
}

//bool Timer::chk_timeout() const{
//    clock_t end_time = clock();
//    if (end_time - start_time >= time_limit * CLOCKS_PER_SEC){
//        return true;
//    }
//    return false;
//}