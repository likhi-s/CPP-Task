#include <iostream>
#include "myclass.h"
using namespace std;

// class A
// {
// public:

//     void(A::*functionptr)();
//     void fun()
//     {
//         (this->*functionptr)();
//     }
//     void print()
//     {
//         cout<<"Hello"<<endl;
//     }

// };


int main()
{
   MyClass obj;
    obj.functionptr =&MyClass::print;
    obj.fun();
}
