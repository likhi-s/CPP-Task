#include "baseobject.h"

BaseObject::BaseObject()
{
    cout<<"BaseObject Constructor Called"<<endl;
}

BaseObject::~BaseObject()
{
    cout<<"BaseObject Destructor Called"<<endl;

}

void BaseObject::print()
{
    cout <<m_name<< " print called" << endl;

    for (auto child : children)
    {
        child->print();
    }
}

void BaseObject::addchild(BaseObject *child)
{
    children.push_back(child);

}

BaseObject::BaseObject(const string name)
{
    m_name = name;
    cout<<"BaseObject Constructor Called"<<endl;
}


string BaseObject::getName()
{
    return m_name;
}

vector<string> BaseObject::findchild(const string &name)
{
    cout<<endl<<"Find child function Called"<<endl;
    vector<string> tempChildList;
    for (auto child : children)
    {
        if (child->getName() == name)
        {
            tempChildList.push_back(name);
        }
    }
    return tempChildList;
}

void BaseObject::getMe()
{
    cout<<m_name<<"  getme Function Called"<<endl;
    for (auto child : children)
    {
        child->getMe();
    }
}





