#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Bureaucrat.hpp"
 #include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm(std::string targ);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const & src);
    virtual void execute(Bureaucrat const & executor) const;

	class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception 
    {
        public:
            virtual const char* what() const throw();
    };

    private:
    std::string target;
};

std::ostream& operator<<(std::ostream & o, ShrubberyCreationForm const & src);
