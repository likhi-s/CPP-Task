#include "myarray.h"


template<typename T, size_t N>
T& MyArray<T, N>::operator[](size_t index) {
    return data[index];
}

template<typename T, size_t N>
const T& MyArray<T, N>::operator[](size_t index) const {
    return data[index];
}

template<typename T, size_t N>
size_t MyArray<T, N>::size() const {
    return N;
}

/*template<typename T, size_t S>
int MyArray<T, S>::size() const
{
    return S;
}


template<typename T, size_t S>
const T MyArray<T, S>::operator[](size_t index) const
{
    return m_data[index];

}

template<typename T, size_t S>
T MyArray<T, S>::operator[](size_t index)
{
    return m_data[index];
}*/
