#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Bureaucrat.hpp"
 #include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    public:
    RobotomyRequestForm(std::string targ);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    RobotomyRequestForm &operator=(RobotomyRequestForm const & src);
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

std::ostream& operator<<(std::ostream & o, RobotomyRequestForm const & src);
