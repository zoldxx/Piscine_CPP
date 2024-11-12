#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
    AForm(std::string name, int gs, int gx);
    virtual ~AForm(void);
    AForm(AForm const &src);
    AForm &operator=(AForm const & src);
    virtual std::string getName(void) const;
    virtual int getgs(void) const;
    virtual int getgx(void) const;
    virtual int get_is_signed(void) const;
    virtual void beSigned(Bureaucrat const & src);
    virtual void change_sign(void);
    virtual void execute(Bureaucrat const & executor) const = 0;

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
    std::string const m_name ;
    bool m_is_signed;  
    int const m_grade_required_to_sign_it;
    int const m_grade_required_to_execute_it;
};

std::ostream& operator<<(std::ostream & o, AForm const & src);
