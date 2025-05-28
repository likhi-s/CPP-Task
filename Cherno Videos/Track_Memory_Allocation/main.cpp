#include <iostream>
#include <memory>
using namespace std;


struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0 ;
    uint32_t CurrentUsage()
    {
        return TotalAllocated - TotalFreed;
    }

};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated+=size;
    return malloc(size);

}

void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.TotalFreed+=size;
    free(memory);
}

struct Object {
    int x,y,z;
    float m;
};
static void PrintMemoryUsage()
{
        cout<<"Memory Usage: "<<s_AllocationMetrics.CurrentUsage()<< " bytes"<<endl;
}

int main()
{

    PrintMemoryUsage();
    string String = "Likhitha";
    PrintMemoryUsage();

    {
        unique_ptr<Object>obj = std::make_unique<Object>();
        //unique_ptr<AllocationMetrics>obj = make_unique<AllocationMetrics>();
        PrintMemoryUsage();

    }
    PrintMemoryUsage();

    cout << "Hello World!" << endl;
    return 0;
}
