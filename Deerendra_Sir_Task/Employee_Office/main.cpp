#include <iostream>
#include "office.h"
#include "employee.h"

using namespace std;

int main()
{
    Office off("pthinks");
    Employee e1("Likhitha", &off);
    Employee e2("Pallavi", &e1);
    Employee e3("Dharshini", &e1);
    Employee e4("Varshini",&e2);
    Employee e5("abc",&e2);
    off.print();

    return 0;
}

