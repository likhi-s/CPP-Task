#include <iostream>
#include <any>
#include <variant>
using namespace std;

void* operator new(size_t size)
{
    return malloc(size);
}
struct CustomClass
{
    string s0,s1;
};

int main()
{

    any data ;
    data = 2;
    data = CustomClass();
    data = string ("likhitha");
    string& s = any_cast<string&>(data);


   /* any data ;
    data = 2;
    data = "likhitha";
    data = string ("likhitha");
   string s = any_cast<string>(data);
    cout<<s<<endl;*/

    /*variant<int,string>data;
    data = 2;
    data = "likhitha";
    string s = get<string>(data);
     cout<<s<<endl;*/

    cout << "Hello World!" << endl;
    return 0;
}
