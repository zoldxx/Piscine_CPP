#include "easyfind.hpp"

int f(void)
{
    static int i = 0;
    i++;
    return (i);
}

void   print(int x)
{
    std::cout << x << std::endl;
}

int main(void)
{
    std::vector<int>  tab(10, 0);
    std::generate(tab.begin(), tab.end(), f);
    for_each(tab.begin(), tab.end(), print);
    easyfind(tab, 4);
    easyfind(tab, 12);
    return (0);
}

