#include "Fixed.hpp"

Fixed::Fixed(void) : _nb(0)
{
    //std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
   // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const nb) : _nb(nb << _bits) 
{
  //  std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float flo): _nb(roundf(flo * (1 << _bits)))
{
	//std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed(void)
{
   // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
   // std::cout << "getRawBits member function called" << std::endl;
    return (this->_nb);
}

void Fixed::setRawBits( int const raw )
{
    this->_nb = raw;
}

float	Fixed::toFloat( void ) const 
{
	return ((float)this->_nb / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const 
{
	return (_nb >> this->_bits);
};

Fixed & Fixed::operator=(Fixed const & rhs)
{
   // std::cout << "Copy assignment operator called" <<std::endl;
    this->_nb = rhs.getRawBits();

    return *this;
}

std::ostream& operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
};

int Fixed::operator<(Fixed const & rhs)
{
    return (this->_nb < rhs.getRawBits());
}

int Fixed::operator>(Fixed const & rhs)
{
    return (this->_nb > rhs.getRawBits());
}

int Fixed::operator<=(Fixed const & rhs)
{
    return (this->_nb <= rhs.getRawBits());
}

int Fixed::operator>=(Fixed const & rhs)
{
    return (this->_nb >= rhs.getRawBits());
}

int Fixed::operator==(Fixed const & rhs)
{
    return (this->_nb == rhs.getRawBits());
}

int Fixed::operator!=(Fixed const & rhs)
{
    return (this->_nb != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const & rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs)
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_nb++;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_nb--;
    return (tmp);
}

Fixed Fixed::operator++(void)
{
    this->_nb++;
    return (*this);
}

Fixed Fixed::operator--(void)
{
    this->_nb--;
    return (*this);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() < b.toFloat())
        return (b);
    return (a);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.toFloat() < b.toFloat())
        return (b);
    return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() > b.toFloat())
        return (b);
    return (a);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.toFloat() > b.toFloat())
        return (b);
    return (a);
}

