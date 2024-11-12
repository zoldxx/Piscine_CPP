#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>

class Bureaucrat
{
    public:
    Bureaucrat(int i, std::string name);
    ~Bureaucrat(void);
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const & src);
    std::string getName(void) const;
    int getGrade(void) const;
    void incremente_grade(void);
    void decremente_grade(void);

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
    int m_grade;
};

std::ostream& operator<<(std::ostream & o, Bureaucrat const & src);
