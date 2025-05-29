#include <iostream>
#include "a.h"
#include "b.h"
#include <thread>

using namespace std;

int main()
{
    A a;
    B b;
    thread t1(&A::fun1,&a);
    thread t2(&B::fun2,&b);

    t1.join();
    t2.join();
    cout << "Hello World!" << endl;
    return 0;
}
