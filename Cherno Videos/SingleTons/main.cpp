#include <iostream>
#include "singleton.h"

using namespace std;

int main()
{
    cout<<"Hii"<<endl;
    //Singleton& instance = Singleton::Get();
    Singleton::Get().fun();

    cout << "Hello World!" << endl;

    return 0;
}

