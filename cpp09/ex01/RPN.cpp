#include "RPN.hpp"

int is_operateur(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (1);
    return (0);
}

int parsing_ok(char *str)
{
    int i = 0;
    if (!isdigit(str[0]))
        return (0);
    while (str[i])
    {
        if (str[i] && !isdigit(str[i]) && !is_operateur(str[i]))
            return (0);
        if (str[i])
            i++;
        if (str[i] && str[i] != ' ')
            return (0);
        if (str[i])
            i++;
    }
    return (1);
}
