#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
    Intern(void);
    ~Intern(void);
    Intern(Intern const &src);
    Intern &operator=(Intern const & src);
    AForm *makeForm(std::string name, std::string target);

	class invalidForm: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream & o, Intern const & src);
