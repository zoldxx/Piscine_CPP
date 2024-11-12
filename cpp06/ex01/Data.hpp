#pragma once
#include <string>
#include <iostream>
#include <stdint.h>

class Data
{
    public:
    Data();
    ~Data();
    Data(Data const &src);
    Data &operator=(Data const & src);
    int get_i(void) const;
    void set_i(int value);

    private:
    int i;
};
