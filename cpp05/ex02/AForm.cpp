#include "AForm.hpp"

AForm::AForm(std::string name, int gs, int gx) : m_name(name), m_grade_required_to_sign_it(gs), m_grade_required_to_execute_it(gx)
{
    if (gs < 1)
        throw AForm::GradeTooHighException();
    else if (gs > 150)
        throw AForm::GradeTooLowException();
    if (gx < 1)
        throw AForm::GradeTooHighException();
    else if (gx > 150)
        throw AForm::GradeTooLowException();
    this->m_is_signed = 0;
    std::cout << "AForm Constructor called" << std::endl;
}

AForm::~AForm(void)
{
     std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(AForm const & src) : m_name(src.m_name), m_is_signed(src.m_is_signed), m_grade_required_to_sign_it(src.m_grade_required_to_sign_it), 
m_grade_required_to_execute_it(src.m_grade_required_to_execute_it)
{
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm & src)
{
    this->m_is_signed = src.m_is_signed;
    std::cout << "AForm Copy assignment operator called" <<std::endl;
     return (*this);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what(void) const throw ()
{
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream & o, AForm const & src)
{
    o << "AForm named " << src.getName() << " need grade " << src.getgs() << " to be signed and grade " << src.getgx() << " to be executed.";
    if (!src.get_is_signed())
        o << " This AForm is not signed." <<std::endl;
    else 
    {
        o << " This AForm is already signed." <<std::endl;
    }
	return (o);
};

std::string AForm::getName(void) const
{
    return(this->m_name);
}

int AForm::getgs(void) const
{
    return(this->m_grade_required_to_sign_it);
}

int AForm::getgx(void) const
{
    return(this->m_grade_required_to_execute_it);
}

int AForm::get_is_signed(void) const
{
    return(this->m_is_signed);
}

void AForm::beSigned(Bureaucrat const & src)
{
    if (src.getGrade() > this->getgs())
         throw AForm::GradeTooLowException();
    this->m_is_signed = 1;
}

void AForm::change_sign(void)
{
    if (this->m_is_signed == 0)
        this->m_is_signed = 1;
    else if (this->m_is_signed == 1)
        this->m_is_signed = 0;
}

