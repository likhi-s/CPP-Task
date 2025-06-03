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
    void print();
    void addchild(BaseObject* child);
    string getName();
    vector<string> findchild(const string &name);
    virtual void getMe();
protected:
    string m_name;
    vector<BaseObject*>children;

};

#endif // BASEOBJECT_H
