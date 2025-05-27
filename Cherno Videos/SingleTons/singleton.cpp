#include "singleton.h"
#include <iostream>
using namespace std;

Singleton Singleton:: s_Instance;

Singleton::Singleton()
{
    std::cout<<"Single Ton COnstructor Called"<<std::endl;
}
Singleton &Singleton::Get()
{
    std::cout<<"Single Ton get fun Called"<<std::endl;

    return s_Instance;
}

void Singleton::fun()
{
    cout<<"function called"<<endl;
}
