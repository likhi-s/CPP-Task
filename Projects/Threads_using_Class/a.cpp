#include "a.h"

A::A() {}

void A::fun1()
{
    std::cout<<"fun1 called"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"fun1 end"<<std::endl;
}
