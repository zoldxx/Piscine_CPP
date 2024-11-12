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

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<( std::ostream &streamOutput, Fixed const &fixedNbr );