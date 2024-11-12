#include "Base.hpp"

int main(void)
{
    Base *src = generate();
    identify(src);
    identify(*src);

    Base *src2 = generate();
    identify(src2);
    identify(*src2);

    Base *src3 = generate();
    identify(src3);
    identify(*src3);

    delete src;
    delete src2;
    delete src3;
    return (0);
}