#pragma once
#include <string>
#include <iostream>

template<typename T >
T   max(T const & x, T const & y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

template<typename T >
T   min(T const & x, T const & y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template<typename T >
void swap(T & x, T & y)
{
    T tmp = x;
    x = y;
    y = tmp;
}