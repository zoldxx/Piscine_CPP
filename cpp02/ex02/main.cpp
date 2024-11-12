#include "Fixed.hpp"

int	main(void)
{
	Fixed a(2);
	Fixed b(2.5f);
	Fixed const c(a);

	std::cout << "surcharge << : a = " << a << "   b = " << b << "   c = " << c << std::endl;

	std::cout << "pre incrementation : a = " << ++a << std::endl;
	std::cout << "a apres pre incrementation : " << a << std::endl;
	std::cout << "post incrementation : a = " << a++ << std::endl;
	std::cout << "a apres post incrementation : " << a << std::endl << std::endl;

	std::cout << "pre decrementation : a = " << --a << std::endl;
	std::cout << "a apres pre decrementation : " << a << std::endl;
	std::cout << "post decrementation : a = " << a-- << std::endl;
	std::cout << "a apres post decrementation : " << a << std::endl << std::endl;

	std::cout << "a = " << a << "   b = " << b << "   a + b = " << a + b << std::endl;
	std::cout << "a = " << a << "   b = " << b << "   a - b = " << a - b << std::endl;
	std::cout << "a = " << a << "   b = " << b << "   a * b = " << a * b << std::endl;
	std::cout << "a = " << a << "   b = " << b << "   a / b = " << a / b << std::endl << std::endl;

	if (a < b)
		std::cout << "a < b" << std::endl;
	else if (b < a)
		std::cout << "b < a" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	else if (b > a)
		std::cout << "b > a" << std::endl;	
	if (a >= c)
		std::cout << "a >= c" << std::endl;
	if (a <= c)
		std::cout << "a <= c" << std::endl;
	if (a == c)
		std::cout << "a == c" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl << std::endl;

	std::cout << "plus grande valeur entre " << a << " et " << b << " : " << Fixed::max(a, b) << std::endl;
	std::cout << "plus petite valeur entre " << a << " et " << b << " : " << Fixed::min(a, b) << std::endl;

	return (0);
}

// int main( void ) 
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }
