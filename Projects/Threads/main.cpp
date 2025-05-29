#include <iostream>
#include <thread>
#include <chrono>

void fun1()
{
    for(int i =0 ;i < 10; i++)
    {
        std::cout<<"fun1 Called"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout<<"fun1 end"<<std::endl;
}
void fun2()
{
    for(int i =0 ;i < 10; i++)
    {
        std::cout<<"fun2 Called"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout<<"fun2 end"<<std::endl;
}
int main()
{

    std::thread t1(fun1);
    std::thread t2(fun2);
    //t1.join();
    t1.detach();
    std::cout<<"hii"<<std::endl;
    //t2.join();
    t2.detach();

    std::this_thread::sleep_for(std::chrono::seconds(120));

    return 0;
}
