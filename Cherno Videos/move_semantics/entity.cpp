#include "entity.h"

Entity::Entity() {}

Entity::Entity(const String &name):m_name(name)
{

}

Entity::Entity(String&& name):m_name((String&&)name)
{
}

void Entity::printName()
{
m_name.print();
}
