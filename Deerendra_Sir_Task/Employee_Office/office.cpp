#include "office.h"

Office::Office()
{
    cout<<"office constructor called"<<endl;
}

Office::~Office()
{
    cout<<"office destructor called"<<endl;
}

void Office::addEmployee(Employee* emp)
{
    cout<<"office constructor called"<<endl;

    employees.push_back(emp);
}

void Office::print()
{
    cout <<m_name << " office print called" << endl;
    for (auto emp : employees)
    {
        emp->print();
        cout<<emp->GetName()<<endl;
    }
}

Office::Office(const string &name)
{
    m_name = name;
}

