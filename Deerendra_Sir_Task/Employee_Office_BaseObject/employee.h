#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "baseobject.h"

class Employee:public BaseObject
{
public:
    Employee();
    Employee(const string& name, BaseObject* baseobject);
    ~Employee();

};

#endif // EMPLOYEE_H
