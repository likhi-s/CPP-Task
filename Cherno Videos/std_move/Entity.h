#ifndef ENTITY_H
#define ENTITY_H
#include "String.h"
#include <iostream>
using namespace std;

class String;
class Entity
{
public:
    Entity();
    Entity(const String& name);
    Entity( String&& name);

    void printName();
private:
    String m_name;

};

#endif // ENTITY_H
