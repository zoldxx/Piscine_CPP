#include "Span.hpp"


Span::Span(unsigned int N) : size(N), i(0)
{}


Span::~Span(void)
{}

Span::Span(Span const &src)
{
    this->tab.resize(src.tab.size());
    this->size = src.size;
    this->i = src.i;
    for (unsigned int k = 0; k < src.i; k++)
        this->tab[k] = src.tab[k];
}

Span &Span::operator=(Span const &src)
{
    this->tab.resize(src.tab.size());
    this->size = src.size;
    this->i = src.i;
    for (unsigned int k = 0; k < src.i; k++)
        this->tab[k] = src.tab[k];
    return (*this);
}

void Span::addNumber(int x)
{
    if (this->i < this->size)
    {
            this->tab.push_back(x);
            this->i++;
    }
    else
        throw std::exception();
}

void Span::print_values(void)
{
    for (std::vector<int>::iterator it = this->tab.begin(); it != this->tab.begin() + this->i; it++)
        std::cout << "[" << *it << "] ";
    std::cout << std::endl;
}

void Span::addNumbers(unsigned int x)
{
    static int i = 0;
    if (i == INT_MAX)
        i = 0;
    unsigned int end = this->i + x;
    for (unsigned int b = this->i; b != end; b++)
        this->addNumber(i++);
}

long Span::shortestSpan(void)
{
    if (this->i < 2)
        throw std::exception();
        
    Span copy(*this);
    std::sort(copy.tab.begin(), copy.tab.begin() + copy.i);
    long res = LONG_MAX;
    for (unsigned int i = 1; i < copy.i; ++i) 
    {
        long dist = copy.tab[i] - copy.tab[i - 1];
        if (dist < res)
            res = dist;
    }
    return (res);
}

long Span::longestSpan(void)
{
    if (this->i < 2)
        throw std::exception();

    Span copy(*this);
    std::sort(copy.tab.begin(), copy.tab.begin() + copy.i);
    return (*(copy.tab.begin() + copy.i - 1) - *copy.tab.begin());
}
