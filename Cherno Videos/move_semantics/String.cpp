#include "String.h"
#include <cstring>

String::String() {}

String::String(const char *string)
{
    cout<<"created"<<endl;
    m_size = strlen(string);
    m_data = new char[m_size+1];
    memcpy(m_data,string,m_size);
}

String::String(const String &other)
{
    cout<<"copied"<<endl;
    m_size = other.m_size;
    m_data = new char[m_size+1];
    memcpy(m_data,other.m_data,m_size);
}

String::String(String&& other) noexcept
{
    cout<<"moved"<<endl;
    m_size = other.m_size;
    m_data = other.m_data;
    other.m_size = 0 ;
    other.m_data = nullptr;
    //memcpy(m_data,other.m_data,m_size);
}

void String ::print()
{
    for(int i = 0; i < m_size;i++)
    {
        cout<<m_data[i];
    }
    cout<<endl;
}
String::~String()
{
    cout<<"Destroyed"<<endl;
    delete m_data;
}
