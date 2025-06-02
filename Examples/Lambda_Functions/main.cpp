#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    auto add = [&]()->int {return a+b;};

    int c = add();
    cout<<c<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
