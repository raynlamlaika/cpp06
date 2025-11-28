#include "Array.hpp"
#include<vector>
#include<iostream>

template <class T>
Array<T>::Array()
{
    std::vector<int> emptyarr;
}
template <class T>
Array<T>::Array(unsigned int n)
{
    int emptyarr[n];
}
