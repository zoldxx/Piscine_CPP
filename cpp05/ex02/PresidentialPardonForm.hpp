#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Bureaucrat.hpp"
 #include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm(std::string targ);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const & src);
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

std::ostream& operator<<(std::ostream & o, PresidentialPardonForm const & src);
