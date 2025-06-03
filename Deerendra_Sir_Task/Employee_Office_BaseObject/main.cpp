#include <iostream>
#include "office.h"
#include "employee.h"

using namespace std;

int main()
{
    Office off("pthinks");

    Employee e1("Likhitha", &off);
    Employee e2("Pallavi", &off);
    Employee e3("Dharshini", &e1);
    Employee e4("Pallavi",&off);
    Employee e5("Likhitha",&off);
    // Employee e3("Dharshini", &e1);
    // Employee e4("Varshini",&e2);
    // Employee e5("abc",&e2);
    off.print();

    vector<string> name = off.findchild("Likhitha");
    for(const auto& childname:name)
    {
        cout<<childname<<endl;
    }


    off.getMe();


    return 0;
}
