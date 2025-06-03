#include "office.h"

Office::Office()
{
    cout<<"office constructor called"<<endl;
}


Office::Office(const string name)
{
    m_name = name;
}

Office::~Office()
{
    cout<<"office destructor called"<<endl;
}
