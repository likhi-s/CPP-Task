#ifndef OFFICE_H
#define OFFICE_H

#include <vector>
#include <string>
#include <iostream>
#include <employee.h>

class Office
{
public:
    Office();
    ~Office();
    void addEmployee(Employee* emp);
    void print();
    Office(const string& name);
private:
    string m_name;
    vector<Employee*> employees;
};

#endif // OFFICE_H
