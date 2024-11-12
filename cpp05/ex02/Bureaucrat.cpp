#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int i, std::string name) : m_name(name)
{
    if (i < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (i > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->m_grade = i;

    std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
     std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : m_name(src.m_name), m_grade(src.m_grade) 
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw ()
{
    return ("Grade is too low");
}

std::string Bureaucrat::getName(void) const
{
    return(this->m_name);
}

int Bureaucrat::getGrade(void) const
{
    return(this->m_grade);
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (o);
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & src)
{
    this->m_grade = src.m_grade;
    std::cout << "Bureaucrat Copy assignment operator called" <<std::endl;
     return (*this);
}

void Bureaucrat::incremente_grade(void)
{
    std::cout << this->getName() << ", bureaucrat grade " << this->getGrade() << ", try to upgrade" << std::endl;
    if (this->m_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->m_grade--;
    std::cout << this->getName() << ", bureaucrat grade " << this->getGrade() << ", has been promoted" << std::endl;
}

void Bureaucrat::decremente_grade(void)
{
    std::cout << this->getName() << ", bureaucrat grade " << this->getGrade() << ", try to downgrade" << std::endl;
        if (this->m_grade + 1 > 150)
            throw Bureaucrat::GradeTooHighException();
    this->m_grade++;
    std::cout << this->getName() << ", bureaucrat grade " << this->getGrade() << ", has been downgraded" << std::endl;
}

void Bureaucrat::signForm(AForm &src)
{
    try
    {
        src.beSigned(*this);
        std::cout << this->getName() << " signed " << src.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        if (this->m_grade > src.getgs())
            std::cout << this->getName() << " couldn't sign " << src.getName() << " because his grade is too low." << std::endl;
        else if (this->m_grade <= src.getgs() && src.get_is_signed() == 1)
            std::cout << this->getName() << " couldn't sign " << src.getName() << " because this form is already signed ! " << std::endl;
        throw AForm::GradeTooLowException();
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        throw AForm::GradeTooLowException();
    }
}
