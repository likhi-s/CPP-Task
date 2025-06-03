#include "myclass.h"

MyClass::MyClass()
{
    cout<<"MyClass Constructor Called"<<endl;
}

void MyClass::fun()
{
    (this->*functionptr)();
}

void MyClass::print()
{
    cout<<"Hello"<<endl;

}
