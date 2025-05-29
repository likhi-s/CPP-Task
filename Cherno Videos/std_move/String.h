#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String
{
public:
    String();
    String(const char* string);
    String(const String& other);
    String& operator=(String&& other) noexcept;
    String( String&& other)noexcept;
    ~String();
    void print();
private:
    char* m_data;
    int m_size;
};

#endif // STRING_H
