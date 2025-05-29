#include <iostream>
#include "String.h"
#include <cstring>
#include "Entity.h"
using namespace std;

int main()
{
    Entity entity(String ("likhitha"));
    entity.printName();

    String apple = "Apple";
    String dest;
    cout<<"apple :";
    apple.print();
    cout<<"dest: ";
    dest.print();
    dest = std::move(apple);
    cout<<"apple :";
    apple.print();
    cout<<"dest: ";
    dest.print();

    /*String string = "Hello likhitha";
    String dest = std::move(string);
    String dest (std::move(string));*/


    cout << "Hello World!" << endl;
    return 0;
}
