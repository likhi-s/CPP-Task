#ifndef MYARRAY_H
#define MYARRAY_H

#include <cstddef>

template<typename T, size_t N>
class MyArray {
private:
    T data[N];

public:
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
};


#endif
