#include "iter.hpp"

int main(void)
{
    int a[3] = {1, 0, 3};
    iter(a, 3, print_val);
     std::cout << "after incrementation : " << std::endl;
    iter(a, 3, incremente);
    iter(a, 3, print_val);
    std::cout << "====================" << std::endl;

    std::string b[3] = {"salut", "ca", "va ?"};
    iter(b, 3, print_val);
    std::cout << "after incrementation : " << std::endl;
    iter(b, 3, incremente);
    iter(b, 3, print_val);
    std::cout << "====================" << std::endl;

    char c[6] = "abcde";
    iter(c, 6, print_val);
    std::cout << "after incrementation : " << std::endl;
    iter(c, 6, incremente);
    iter(c, 6, print_val);
}
