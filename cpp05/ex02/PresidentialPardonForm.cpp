#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targ) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = targ;
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
     std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src.getName(), src.getgs(), src.getgx())
{
    if (src.get_is_signed() != this->get_is_signed())
        this->change_sign();
    this->target = src.target;
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & src)
{
    if (src.get_is_signed() != this->get_is_signed())
        this->change_sign();
    this->target = src.target;
    std::cout << "PresidentialPardonForm Copy assignment operator called" <<std::endl;
     return (*this);
}

const char *PresidentialPardonForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char *PresidentialPardonForm::GradeTooLowException::what(void) const throw ()
{
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream & o, PresidentialPardonForm const & src)
{
    o << "PresidentialPardonForm " << "need grade " << src.getgs() << " to be signed and grade " << src.getgx() << " to be executed.";
    if (!src.get_is_signed())
        o << " This PresidentialPardonForm is not signed." <<std::endl;
    else 
    {
        o << " This PresidentialPardonForm is already signed." <<std::endl;
    }
	return (o);
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (this->get_is_signed() == 0 || this->getgx() < executor.getGrade())
            throw AForm::GradeTooLowException();

        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    catch (std::exception & e)
    {
        if (this->get_is_signed() == 0 && this->getgx() < executor.getGrade())
             std::cout << executor.getName() << " can't execute the form because it's not signed and his grade is too low for execute this form." << std::endl;
        else if (this->get_is_signed() == 0)
              std::cout << executor.getName() << " can't execute the form because it's not signed." << std::endl;
        else if (this->getgx() < executor.getGrade())
            std::cout << executor.getName() << " can't execute the form because his grade is too low for execute this form." << std::endl;
        throw AForm::GradeTooLowException();
    }
}
