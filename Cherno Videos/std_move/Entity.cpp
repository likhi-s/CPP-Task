#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const String &name):m_name(name)
{

}

Entity::Entity(String&& name):m_name(std::move(name))
{
}

void Entity::printName()
{
    m_name.print();
}
