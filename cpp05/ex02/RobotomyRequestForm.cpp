#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string targ) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = targ;
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
     std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src.getName(), src.getgs(), src.getgx())
{
    if (src.get_is_signed() != this->get_is_signed())
        this->change_sign();
    this->target = src.target;
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & src)
{
    if (src.get_is_signed() != this->get_is_signed())
        this->change_sign();
    this->target = src.target;
    std::cout << "RobotomyRequestForm Copy assignment operator called" <<std::endl;
     return (*this);
}

const char *RobotomyRequestForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char *RobotomyRequestForm::GradeTooLowException::what(void) const throw ()
{
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream & o, RobotomyRequestForm const & src)
{
    o << "RobotomyRequestForm" << " need grade " << src.getgs() << " to be signed and grade " << src.getgx() << " to be executed.";
    if (!src.get_is_signed())
        o << " This RobotomyRequestForm is not signed." <<std::endl;
    else 
    {
        o << " This RobotomyRequestForm is already signed." <<std::endl;
    }
	return (o);
};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int i = 0;
    try
    {
        if (this->get_is_signed() == 0 || this->getgx() < executor.getGrade())
            throw AForm::GradeTooLowException();

        std::cout << "* BRRRRGNGERGTRGRNTGRT BRRRGRTGRTGRT * " << std::endl;
        if (i == 0)
        {
            std::cout << this->target << " has been robotomized successfully." << std::endl;
            i = 1;
        }
        else if (i == 1)
        {
            std::cout << "the robotomy failed." << std::endl;
            i = 0;
        }
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
