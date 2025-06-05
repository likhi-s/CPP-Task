#include <iostream>
#include "office.h"
#include "employee.h"

using namespace std;


int main()
{
    Office off("PthinkS");

    Employee e1("Likhitha", &off);
    Employee e2("Pallavi", &off);
    Employee e3("Dharshini", &off);
    Employee e4("Varshini",&off);
    Employee e5("abc",&e4);

    off.print();
    off.getMe();

    vector<BaseObject*> name = off.findchild("Likhitha");
    for(auto childname:name)
    {
        cout<<childname->getName()<<endl;
    }

    vector<BaseObject*> Name = e4.findchild("abc");
    for(auto childname:Name)
    {
        cout<<childname->getName()<<endl;
    }


    return 0;
}
