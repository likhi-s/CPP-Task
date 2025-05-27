#include <iostream>
#include <cstdint>
#include <cstdlib>
using namespace std;

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
    s_AllocCount++;
    cout << "Allocating " << size << " bytes" << endl;
    return malloc(size);
}

void printName(const string_viewS name)
{
    cout << name << endl;
}

int main()
{
    string name = "Likhitha";
    // string fName = name.substr(0,3);
    // string lName = name.substr(4,7);

    string_view fName(name.c_str(),3);
    string_view lName(name.c_str()+4,7);

    printName(name.substr(4,7));

    cout << s_AllocCount << " allocations" << endl;
    return 0;
}
