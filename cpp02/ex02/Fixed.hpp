#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int _nb;
    const static int _bits = 8;

    public:
    Fixed(void);
    Fixed(Fixed const & src);

    Fixed(int const nb);
    Fixed(float const nb);

    ~Fixed(void);

    Fixed & operator=(Fixed const & rhs);

    int operator<(Fixed const & rhs);
    int operator>(Fixed const & rhs);
    int operator<=(Fixed const & rhs);
    int operator>=(Fixed const & rhs);
    int operator==(Fixed const & rhs);
    int operator!=(Fixed const & rhs);

    Fixed operator+(Fixed const & rhs);
    Fixed operator-(Fixed const & rhs);
    Fixed operator*(Fixed const & rhs);
    Fixed operator/(Fixed const & rhs);

    Fixed operator++(int);
    Fixed operator--(int);
    Fixed operator++(void);
    Fixed operator--(void);

    static    Fixed  &max(Fixed &a, Fixed &b);
    static    Fixed  &min(Fixed &a, Fixed &b);
    static    const Fixed  &max(Fixed const &a, Fixed const &b);
    static    const Fixed  &min(Fixed const &a, Fixed const &b);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<( std::ostream &streamOutput, Fixed const &fixedNbr );