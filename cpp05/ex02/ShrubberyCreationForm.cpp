#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string targ) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = targ;
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
     std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src.getName(), src.getgs(), src.getgx())
{
    if (src.get_is_signed() != this->get_is_signed())
        this->change_sign();
    this->target = src.target;
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & src)
{
    if (src.get_is_signed() != this->get_is_signed())
        this->change_sign();
    this->target = src.target;
    std::cout << "ShrubberyCreationForm Copy assignment operator called" <<std::endl;
     return (*this);
}

const char *ShrubberyCreationForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade is too high");
}

const char *ShrubberyCreationForm::GradeTooLowException::what(void) const throw ()
{
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream & o, ShrubberyCreationForm const & src)
{
    o << "ShrubberyCreationForm" << " need grade " << src.getgs() << " to be signed and grade " << src.getgx() << " to be executed.";
    if (!src.get_is_signed())
        o << " This ShrubberyCreationForm is not signed." <<std::endl;
    else 
    {
        o << " This ShrubberyCreationForm is already signed." <<std::endl;
    }
	return (o);
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (this->get_is_signed() == 0 || this->getgx() < executor.getGrade())
            throw AForm::GradeTooLowException();
        
        std::string str = this->target + "_shrubbery";
        const char* nomFichier = str.c_str();
        std::ofstream fichierSortie(nomFichier);
        if (fichierSortie.is_open()) 
        {
            fichierSortie << "      ^      " << std::endl;
            fichierSortie << "     / \\     " << std::endl;
            fichierSortie << "    /   \\    " << std::endl;
            fichierSortie << "   /     \\   " << std::endl;
            fichierSortie << "  /_______\\  " << std::endl;
            fichierSortie << "      |      " << std::endl;
            fichierSortie << "      |      " << std::endl;
            fichierSortie.close();
        } 
        else
            std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
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
