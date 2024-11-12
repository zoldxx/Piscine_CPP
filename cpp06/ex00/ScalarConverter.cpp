#include "ScalarConverter.hpp"

int is_int(std::string str)
{
    int i = 0;
    if (str[i] && (str[i] == '+' || str[i] == '-'))
        i++;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int is_char(std::string str)
{
    if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
        return (1);
    return (0);
}

int is_double(std::string str)
{
    int i = 0;
    if (str[i] && (str[i] == '+' || str[i] == '-'))
        i++;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
            i++;
    if (str[i] != '.')
        return (0);
    i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '\0')
        return (1);
    return (0);
}

int is_float(std::string str)
{
    int i = 0;
    if (str[i] && (str[i] == '+' || str[i] == '-'))
        i++;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
            i++;
    if (str[i] != '.')
        return (0);
    i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] && str[i] == 'f' && str[i + 1] == '\0')
        return (1);
    return (0);
}

int find_type(std::string str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf"
        || str == "-inf" || str == "+inf" || str == "nan")
        return (1);
    else if (is_char(str))
        return (2);
    else if (is_int(str))
        return (3);
    else if (is_double(str))
        return (4);
    else if (is_float(str))
        return (5);
    else
        return (6);
}

void print_values(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nanf" || str == "-inff" || str == "+inff")
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
    }
}

void print_char(std::string str)
{
    char c = str[0];
    if (!(c >= '0' && c <= '9'))
        std::cout << "char: " << c << std::endl;
    else 
        std::cout << "char: non displayable" << std::endl;

    int chartoint = static_cast<int>(c);
    float chartofloat = static_cast<float>(c);
    double chartodouble = static_cast<double>(c);

    std::cout << "int: " << chartoint << std::endl;
    std::cout << "float: " << chartofloat << ".0f" << std::endl;
    std::cout << "double: " << chartodouble << ".0" << std::endl;
}

void print_int(std::string str)
{
    errno = 0;
    char *endptr;

    long l = std::strtol(str.c_str(), &endptr, 10);
    if (errno == ERANGE || l > 2147483647 || l < -2147483648) 
    {
        std::cout << "conversion impossible (overflow)" << std::endl;
        return ;
    }

    int i = std::atoi(str.c_str());
    if ((i >= 0 && i < 32) || (i > 126 && i < 256))
        std::cout << "char: non displayable" << std::endl;
    else if (i >= 256 || i < 0) 
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(i);
        std::cout << "char: " << c << std::endl;
    }

    float inttofloat = static_cast<float>(i);
    double inttodouble = static_cast<double>(i);

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << inttofloat << ".0f" << std::endl;
    std::cout << "double: " << inttodouble << ".0" << std::endl;
}

int only_zero_after_point(std::string str)
{
    int i = 0;

    while (str[i] != '.')
        i++;
    i++;
    while (str[i] == '0')
        i++;
    if (!str[i])
        return (1);
    return (0);
}

int only_zero_after_point_float(std::string str)
{
    int i = 0;

    while (str[i] != '.')
        i++;
    i++;
    while (str[i] == '0')
        i++;
    if (str[i] == 'f')
        return (1);
    return (0);
}

void print_double(std::string str)
{
    errno = 0;
    char *endptr;

    double d = std::strtod(str.c_str(), &endptr);
    if (errno == ERANGE) 
    {
        std::cout << "conversion impossible (overflow)" << std::endl;
        return ;
    }
    if ((d >= 0 && d < 32) || (d > 126 && d < 256))
        std::cout << "char: non displayable" << std::endl;
    else if (d >= 256 || d < 0) 
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(d);
        std::cout << "char: " << c << std::endl;
    }
    if (d > INT_MAX)
        std::cout << "int: impossible (overflow)" << std::endl;
    else if (d < INT_MIN)
        std::cout << "int: impossible (underflow)" << std::endl;
    else
    {
         int doubletoint = static_cast<int>(d);
         std::cout << "int: " << doubletoint << std::endl;
    }
    if (d > FLT_MAX)
        std::cout << "float: impossible (overflow)" << std::endl;
    else
    {
        float doubletofloat = static_cast<float>(d);
        if (only_zero_after_point(str))
            std::cout << "float: " << doubletofloat << ".0f" << std::endl;
        else 
            std::cout << "float: " << doubletofloat << "f" << std::endl;
    }
    if (only_zero_after_point(str))
        std::cout << "double: " << d << ".0" << std::endl;
    else 
        std::cout << "double: " << d << std::endl;
}

void print_float(std::string str)
{
    errno = 0;
    char *endptr;

    float f = std::strtof(str.c_str(), &endptr);
    if (errno == ERANGE) 
    {
        std::cout << "conversion impossible (overflow)" << std::endl;
        return ;
    }
    if (f < 32 || (f > 126 && f < 256))
        std::cout << "char: non displayable" << std::endl;
    else if (f >= 256)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(f);
        std::cout << "char: " << c << std::endl;
    }
    // if (f > static_cast<float>(INT_MAX))
    //     std::cout << "int: impossible (overflow)" << std::endl;
    // else if (f < static_cast<float>(INT_MIN))
    //     std::cout << "int: impossible (underflow)" << std::endl;
    if (f > 2147480000.0f)
        std::cout << "int: impossible (overflow)" << std::endl;
    else if (f < -2147480000.0f)
        std::cout << "int: impossible (underflow)" << std::endl;
    else
    {
         int floattoint = static_cast<int>(f);
         std::cout << "int: " << floattoint << std::endl;
    }
    if (only_zero_after_point_float(str))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    double floattodouble = static_cast<double>(f);
    if (only_zero_after_point_float(str))
        std::cout << "double: " << floattodouble << ".0" << std::endl;
    else
        std::cout << "double: " << floattodouble << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    int i = find_type(str);
    if (i == 1)
        print_values(str);
    else if (i == 2)
        print_char(str);
    else if (i == 3)
        print_int(str);
    else if (i == 4)
        print_double(str);
    else if (i == 5)
        print_float(str);
    else
         std::cout << "error : undefined type" << std::endl;
}
