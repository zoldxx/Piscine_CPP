#pragma once
#include <string>
#include <iostream>

template<typename T >
void  iter(T *x, int y, void z(T &x))
{
    int i = 0;
    while (i < y)
    {
        z(x[i]);
        i++;
    }
}


template<typename T >
void  print_val(T &x)
{
    std::cout << x << std::endl;
}

template<typename T >
void incremente(T &i)
{
    i += 1;
}
