#include "RPN.hpp"

int main(int ac, char **av) 
{
    if (ac != 2 || !parsing_ok(av[1]))
        return (std::cout << "Error" << std::endl, 1);

    std::stack<int> pile;
    std::string line = av[1];
    int i = 0;
    int a = 0;
    int b = 0;
    while (line[i])
    {
        if (isdigit(line[i]))
            pile.push(line[i] - 48);
        else if (is_operateur(line[i]) && pile.size() < 2)
            return (std::cout << "Error : too much operators" << std::endl, 1);
        else if (is_operateur(line[i]) && pile.size() >= 2)
        {
            a = pile.top();
            pile.pop();
            b = pile.top();
            pile.pop();
            if (line[i] == '+')
                pile.push(a + b);
            else if (line[i] == '-')
                pile.push(b - a);
            else if (line[i] == '*')
               pile.push(a * b);
            else if (line[i] == '/')
                pile.push(b / a);
        }
        i++;
    }
    if (pile.size() != 1)
        return (std::cout << "Error : too much numbers" << std::endl, 1);
    std::cout << pile.top() << std::endl;
    return (0);
}

