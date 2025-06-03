#ifndef MYCLASS_H
#define MYCLASS_H
#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass();
    void (MyClass::*functionptr)();
    void fun();
    void print();
};

#endif // MYCLASS_H
