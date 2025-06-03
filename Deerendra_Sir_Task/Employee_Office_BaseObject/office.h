#ifndef OFFICE_H
#define OFFICE_H
#include "baseobject.h"

class Office:public BaseObject
{
public:
    Office();
    Office(const string name);
    ~Office();
};

#endif // OFFICE_H
