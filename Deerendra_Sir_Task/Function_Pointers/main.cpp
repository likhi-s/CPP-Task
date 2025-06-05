#include <iostream>
#include "myclass.h"
using namespace std;

int main()
{
    MyClass obj;  
    obj.functionptr =&MyClass::print;
    obj.fun();
}
