#include "b.h"

B::B()
{

}

void B::fun2()
{
    std::cout<<"fun2 called"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"fun2 end"<<std::endl;
}
