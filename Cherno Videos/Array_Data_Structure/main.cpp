#include <iostream>
#include "myarray.h"

int main() {
    MyArray<int, 10> collection;

    for (size_t i = 0; i < collection.size(); ++i) {
        collection[i] = i * 2;
    }

    for (size_t i = 0; i < collection.size(); ++i) {
        std::cout << collection[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}
