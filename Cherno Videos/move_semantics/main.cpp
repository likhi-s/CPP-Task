#include <iostream>
#include "String.h"
#include "entity.h"
using namespace std;

int main()
{
    Entity entity(String ("likhitha"));
    entity.printName();

    cout << "Hello World!" << endl;
    return 0;
}
