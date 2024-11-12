#include "Fixed.hpp"

Fixed::Fixed(void) : _nb(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const nb) : _nb(nb << _bits) 
{
    std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float flo): _nb(roundf(flo * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nb);
}

void Fixed::setRawBits( int const raw )
{
    this->_nb = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    this->_nb = rhs.getRawBits();

    return *this;
}

std::ostream& operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
};

float	Fixed::toFloat( void ) const 
{
	return ((float)this->_nb / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const 
{
	return (_nb >> this->_bits);
};



