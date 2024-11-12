#include "Bureaucrat.hpp"

int main(void)
{
    try
	{
        std::cout << "try to create a bureaucrat with a grade of 200 : " << std::endl;
		Bureaucrat b(200, "Bureaucrate ");
	} 
	catch (std::exception& e)
	{
		 std::cout << e.what() << std::endl;
	}
    try
	{
        std::cout << "try to create a bureaucrat with a grade of 0 : " << std::endl;
		Bureaucrat b(0, "Bureaucrate ");
	} 
	catch (std::exception& e)
	{
		 std::cout << e.what() << std::endl;
	}
    try
	{
        std::cout << "try to create a bureaucrat with a grade of 2 : " << std::endl;
		Bureaucrat b(2, "Oscar de la compta");
        std::cout << b;
        Bureaucrat d = b;
        d.incremente_grade();
        d.incremente_grade();
        std::cout << d;
	}
    catch (std::exception& e)
	{
		 std::cout << e.what() << std::endl;
	}
    try
	{
        std::cout << "try to create a bureaucrat with a grade of 149 : " << std::endl;
		Bureaucrat c(149, "toby le RH");
        std::cout << c;
        Bureaucrat d(c);
        d.decremente_grade();
        d.decremente_grade();
        std::cout << d;
	}
    catch (std::exception& e)
	{
		 std::cout << e.what() << std::endl;
	}
    return (0);
}
