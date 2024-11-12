#include "Span.hpp"

int main(void)
{
    try 
    {
        Span sp(3);
        std::cout << "try to add 5 numbers in array of size 3 :" << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.print_values();
    }
    catch (std::exception &e)
    {
        std::cout << "array is full" << std::endl << std::endl;
    }
    try 
    {
        Span sp(5);
        std::cout << "try to add 1 numbers in array of size 5 :" << std::endl;
        sp.addNumber(6);
        sp.print_values();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "not enough datas to calculate span" << std::endl << std::endl;
    }
    try 
    {
        Span sp(5);
        std::cout << "try to add 5 numbers in array of size 5 :" << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.print_values();
        std::cout << "shortest span is " << sp.shortestSpan() << std::endl;
        std::cout << "longuest span is " << sp.longestSpan() << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "array is full" << std::endl;
    }
    try 
    {
        Span sp(15000);
        std::cout << "try to add 10000 numbers in array of size 15000 :" << std::endl;
        sp.addNumbers(10000);
        std::cout << "shortest span is " << sp.shortestSpan() << std::endl;
        std::cout << "longuest span is " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "array is full" << std::endl;
    }
    return 0;
}
