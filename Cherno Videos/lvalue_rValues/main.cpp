#include <iostream>
using namespace std;

void printName(string&& name)//rvalue Reference -rvalues are temporary values
{
    cout<< name <<endl;
}
void printName(string& name)// lvalue Reference
{
    cout<< name <<endl;
}

int main()
{
    string firstName = "Likhi";
    string secondName = "tha";

    string fullName = firstName + secondName;
    printName(fullName);
    printName(firstName + secondName);
}



























/*int& getValue()
{
    static int value = 10;
    return value;
}

void setValue(const int& value)
{

}
int main()
{

    int i = 10;
    const int& a = 10;
    setValue(i);
    setValue(10);

    // int i = getValue();
    // getValue() = 5;
    // int a = i;

    cout << "Hello World!" << endl;
    return 0;
}*/
