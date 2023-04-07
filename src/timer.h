// Author: Cao Rui

#include <functional>

class Timer{
public:
    Timer();

    void start(int);
    bool timeout();
private:
    static bool timeout_flag;
    static void wait(int);
};