#include "employee.h"

Employee::Employee()
{
    cout<<"employee constructor called"<<endl;
}

Employee::Employee(const string& name, BaseObject* baseobject): BaseObject(name),m_baseobject(baseobject)
{
    cout<<"employee constructor called"<<endl;
    if (m_baseobject)
    {
        m_baseobject->addchild(this);
    }
}

Employee::~Employee()
{
    cout<<"employee destructor called"<<endl;
}



