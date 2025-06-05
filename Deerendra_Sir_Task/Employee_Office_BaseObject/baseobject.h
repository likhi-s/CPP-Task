#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <string>
#include <iostream>
using namespace std;
#include <vector>

class BaseObject
{
public:
    BaseObject();
    BaseObject(const string name);
    ~BaseObject();

    virtual void print();
    virtual vector<BaseObject*> findchild(const string &name);
    virtual void getMe();

    void addchild(BaseObject* child);
    string getName();

protected:
    string m_name;
    vector<BaseObject*>m_children;

};

#endif // BASEOBJECT_H
