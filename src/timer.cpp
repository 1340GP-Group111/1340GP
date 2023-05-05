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
