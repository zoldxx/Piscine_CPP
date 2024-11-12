#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#define MAX_VAL 750


template<typename T >
class Array
{
    public:
    Array(void);
    Array(unsigned int n);
    Array(Array const & src);
    virtual ~Array(void);
    Array &operator=(Array const & src);
    unsigned int size(void) const;
    void  print_val(unsigned int n);
    void modify_val(unsigned int i, T new_value);
    T &operator[](unsigned int index);

    private:
    T *array;
    unsigned int _size; 
};

template<typename T >
Array<T>::Array(void)
{
    this->array = NULL;
    this->_size = 0;
    std::cout << "Default Array Constructor called" << std::endl;
}

template<typename T >
Array<T>::~Array(void)
{
    if (this->array)
    {
        delete [] this->array;    
        this->array = NULL;
    }
    std::cout << "Array Destructor called" << std::endl;
}

template<typename T >
Array<T>::Array(unsigned int n)
{
    try
    {
        this->array = new T[n];
        this->_size = n;
        std::cout << "Array Constructor called" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "allocation of memory fail" << std::endl;
    }
}

template<typename T >
Array<T>::Array(Array const & src)
{
    try
    {   unsigned int n = src.size();
        this->array = new T[n];
        for (unsigned int i = 0; i < n; i++)
            this->array[i] = src.array[i];
        this->_size = n;
        std::cout << "Array Copy constructor called" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "allocation of memory fail" << std::endl;
    }
}

template<typename T >
Array<T> &Array<T>::operator=(const Array & src)
{
    try
    {   unsigned int n = src.size();
        if (this->array)
            delete[] this->array;
        this->array = new T[n];
        this->_size = n;
        for (unsigned int i = 0; i < n; i++)
            this->array[i] = src.array[i];
        std::cout << "Array Copy assignment operator called" <<std::endl;
        return (*this);
    }
    catch (std::exception & e)
    {
        std::cout << "allocation of memory fail" << std::endl;
        return (*this);
    }
}

template<typename T >
void  Array<T>::print_val(unsigned int n)
{
    try
    {
        if (n > this->size() - 1)
            throw std::exception();
        std::cout << this->array[n] << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "can't acces this value because it's out of bounds of the array" << std::endl;
    }
}

template<typename T >
void Array<T>::modify_val(unsigned int i, T new_value)
{
    try
    {
        if (i > this->size() - 1)
            throw std::exception();
        this->array[i] = new_value;
    }
    catch (std::exception &e)
    {
         std::cout << "can't change this value : index is out of array's bounds " << std::endl;
    }
}

template<typename T >
unsigned int Array<T>::size(void) const
{
    return (this->_size);
}

template<typename T >
T& Array<T>::operator[](unsigned int index) 
{
    if (index >= this->_size)
    {
        throw std::exception();
    }
    return (this->array[index]);
}
