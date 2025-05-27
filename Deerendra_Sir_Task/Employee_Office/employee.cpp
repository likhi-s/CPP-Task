#include "employee.h"
#include "office.h"

Employee::Employee(const string& name, Office* office): name(name), officePtr(office)
{
    cout<<"employee constructor with office parameter"<<endl;
    if (officePtr)
    {
        officePtr->addEmployee(this);
    }
}

Employee::Employee(const string &name, Employee* emp): name(name), empPtr(emp)
{
    cout<<"employee constructor with employee parameter"<<endl;
    if (empPtr)
    {
        empPtr->addChild(this);
    }
}

Employee::~Employee()
{
    cout<<"employee destructor called"<<endl;
}

string Employee::GetName()
{
    return name;
}

void Employee::addChild(Employee* child)
{
    children.push_back(child);
}

void Employee::print()
{
    //cout << "employee print called" << endl;
    cout <<name<< " employee  print called" << endl;

    for (auto child : children)
    {
        child->print();
    }
}


