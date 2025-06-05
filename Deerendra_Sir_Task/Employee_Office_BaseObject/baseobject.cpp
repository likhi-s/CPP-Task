#include "baseobject.h"

BaseObject::BaseObject()
{
    cout<<"BaseObject Constructor Called"<<endl;
}

BaseObject::BaseObject(const string name)
{
    m_name = name;
    cout<<"BaseObject Constructor Called"<<endl;
}


BaseObject::~BaseObject()
{
    cout<<"BaseObject Destructor Called"<<endl;

}

void BaseObject::print()
{
    cout <<m_name<< " print called" << endl;

    for (BaseObject* child : m_children)
    {
        child->print();
    }
}

void BaseObject::addchild(BaseObject *child)
{
    m_children.push_back(child);

}

string BaseObject::getName()
{
    return m_name;
}

vector<BaseObject *> BaseObject::findchild(const string &name)
{
    cout<<endl<<"Find child function Called"<<endl;
    vector<BaseObject*> tempChildList;
    for (BaseObject* child : m_children)
    {
        if (child->getName() == name)
        {
            tempChildList.push_back(child);
        }
    }
    return tempChildList;
}

void BaseObject::getMe()
{
    cout<<m_name<<"  getme Function Called"<<endl;
    for (BaseObject* child : m_children)
    {
        child->getMe();
    }
}





