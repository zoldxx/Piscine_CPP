#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		RobotomyRequestForm a("creed the undercover");
		Bureaucrat b(100, "creed the undercover");

		std::cout << a;
		std::cout << b;
		b.signForm(a);
		b.executeForm(a);
	}
	catch (std::exception & e)
	{
		std::cout << "an error has occurred" << std::endl << std::endl;
	}
	try
	{
		RobotomyRequestForm a("creed the undercover");
		Bureaucrat b(72, "creed the undercover");

		std::cout << a;
		std::cout << b;
		b.signForm(a);
		b.executeForm(a);
	}
	catch (std::exception & e)
	{
		std::cout << "an error has occurred" << std::endl << std::endl;
	}
	try
	{
		RobotomyRequestForm a("creed the undercover");
		Bureaucrat b(20, "creed the undercover");

		std::cout << a;
		std::cout << b;
		b.executeForm(a);
	}
	catch (std::exception & e)
	{
		std::cout << "an error has occurred" << std::endl << std::endl;
	}
	try
	{
		RobotomyRequestForm a("creed the undercover");
		Bureaucrat b(20, "creed the undercover");

		std::cout << a;
		std::cout << b;
		b.signForm(a);
		b.executeForm(a);
		b.executeForm(a);
		b.executeForm(a);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "an error has occurred" << std::endl << std::endl;
	}
	try
	{
		ShrubberyCreationForm a("pam");
		Bureaucrat b(123, "pam");

		std::cout << a;
		std::cout << b;
		b.signForm(a);
		b.executeForm(a);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "an error has occurred" << std::endl << std::endl;
	}
	try
	{
		PresidentialPardonForm a("ryan the ambitious");
		Bureaucrat b(5, "ryan the ambitious");

		std::cout << a;
		std::cout << b;
		b.signForm(a);
		b.executeForm(a);
		std::cout << std::endl;
		b.decremente_grade();
		b.executeForm(a);
	}
	catch (std::exception & e)
	{
		std::cout << "an error has occurred" << std::endl << std::endl;
	}
	return (0);
}
