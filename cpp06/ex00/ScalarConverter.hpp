#pragma once
#include <string>
#include <iostream>
#include <cerrno>
#include <stdlib.h>
#include <cfloat>
#include <climits>

class ScalarConverter
{
    public:
    void static convert(std::string str);

    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &src);
    ScalarConverter &operator=(ScalarConverter const & src);
};
