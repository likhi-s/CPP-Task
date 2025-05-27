#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;
#include <vector>

class Office;

class Employee
{
public:
    Employee(const string& name, Office* office);
    Employee(const string& name, Employee* emp);
    ~Employee();

    string GetName();
    void print();
    void addChild(Employee* child);
private:
    std::string name;
    Office* officePtr;
    Employee* empPtr;
    std::vector<Employee*> children;
};

#endif // EMPLOYEE_H
