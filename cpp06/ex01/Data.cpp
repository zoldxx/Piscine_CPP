#include "Data.hpp"

Data::Data(void)
{
    this->i = 42;
    std::cout << "Data Constructor called" << std::endl;
}

Data::Data(Data const & src)
{
    this->i = src.get_i();
    std::cout << "Data Copy constructor called" << std::endl;
}

Data::~Data(void)
{
     std::cout << "Data destructor called" << std::endl;
}

Data &Data::operator=(const Data & src)
{
    this->i = src.get_i();
     std::cout << "Data Copy assignment operator called" <<std::endl;
     return (*this);
}


int Data::get_i(void) const
{
    return(this->i);
}

void Data::set_i(int value)
{
    this->i = value;
}

