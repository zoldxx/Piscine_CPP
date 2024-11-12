#include <iostream>

class Fixed
{
    private:
    int _nb;
    const static int _bits = 8;

    public:
    Fixed(void);
    ~Fixed(void);
    Fixed(Fixed const & src);
    Fixed & operator=(Fixed const & rhs);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};