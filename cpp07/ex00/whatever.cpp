

#include "whatever.hpp"

template <class T>


void swap(T var1, T var2)
{
    T swap;

    swap = var1;
    var1 = var2;
    var2 = swap;
}
template <class T>

T min(T var1, T var2)
{
    return (var1 > var2 ? var2 : var1);
}

template <typename T>

T max(T var1, T var2)
{
    return (var1 < var2 ? var2 : var1);
}