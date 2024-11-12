#include "whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}

// int main(void)
// {
//     int a = 1;
//     int b = 2;
//     std::cout << "a = " << a << " | b = " << b << " | the higher is " << max(a, b) << " | the lower is " << min(a, b) << std::endl;
//     std::cout << "swap values of a and b :" << std::endl;
//     swap(a, b);
//     std::cout << "a = " << a << " | b = " << b << " | the higher is " << max(a, b) << " | the lower is " << min(a, b) << std::endl << std::endl;

//     float c = 3.14;
//     float d = 56.8;
//     std::cout << "c = " << c << " | d = " << d << " | the higher is " << max(c, d) << " | the lower is " << min(c, d) << std::endl;
//     std::cout << "swap values of c and d :" << std::endl;
//     swap(c, d);
//     std::cout << "c = " << c << " | d = " << d << " | the higher is " << max(c, d) << " | the lower is " << min(c, d) << std::endl << std::endl;

//     char e = 'e';
//     char f = 'f';
//     std::cout << "e = " << e << " | f = " << f << " | the higher is " << max(e, f) << " | the lower is " << min(e, f) << std::endl;
//     std::cout << "swap values of e and f :" << std::endl;
//     swap(e, f);
//     std::cout << "e = " << e << " | f = " << f << " | the higher is " << max(e, f) << " | the lower is " << min(e, f) << std::endl << std::endl;

//     std::string g = "salut";
//     std::string h = "hello";
//     std::cout << "g = " << g << " | h = " << h << " | the higher is " << ::max(g, h) << " | the lower is " << ::min(g, h) << std::endl;
//     std::cout << "swap values of e and f :" << std::endl;
//     ::swap(g, h);
//     std::cout << "g = " << g << " | h = " << h << " | the higher is " << ::max(g, h) << " | the lower is " << ::min(g, h) << std::endl;
// }
