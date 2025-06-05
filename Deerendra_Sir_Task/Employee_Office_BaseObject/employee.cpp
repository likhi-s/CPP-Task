#include "employee.h"

Employee::Employee()
{
    cout<<"employee constructor called"<<endl;
}

Employee::Employee(const string& name, BaseObject* baseobject): BaseObject(name)
{
    cout<<"employee constructor called"<<endl;
    if (baseobject)
    {
        baseobject->addchild(this);
    }
}

Employee::~Employee()
{
    cout<<"employee destructor called"<<endl;
}



