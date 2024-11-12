#include "PhoneBook.hpp"

void    PhoneBook::add(Contact *ami)
{
    std::cout << std::endl;
    while (1)
    {
        if (std::cin.eof())
            exit(1);
        std::cout << "First name :" << std::endl;
        getline(std::cin, ami->first_name);
        if (ami->first_name.length() >= 1)
            break ;
    }
    while (1)
    {
        if (std::cin.eof())
            exit(1);
        std::cout << std::endl << "last name :" << std::endl;
        getline(std::cin, ami->last_name);
        if (ami->last_name.length() >= 1)
            break ;
    }
    while (1)
    {
        if (std::cin.eof())
            exit(1);
        std::cout << std::endl << "nickname :" << std::endl;
        getline(std::cin, ami->nickname);
        if (ami->nickname.length() >= 1)
            break ;
    }
    while (1)
    {
        if (std::cin.eof())
            exit(1);
        std::cout << std::endl << "phone number :" << std::endl;
        getline(std::cin, ami->phone_number);
        if (ami->phone_number.length() >= 1)
            break ;
    }
    while (1)
    {
        if (std::cin.eof())
            exit(1);
        std::cout << std::endl << "darkest secret :" << std::endl;
        getline(std::cin, ami->darkest_secret);
        if (ami->darkest_secret.length() >= 1)
            break ;
    }
    std::cout << std::endl;
}

void    PhoneBook::search(PhoneBook *rep)
{
    std::cout << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "|__________|__________|__________|__________|" << std::endl;
    int i = 0;
    while (i < 8)
    {
        std::cout << "|         " << i + 1 << "|";

        if (rep->contact[i].first_name.length() > 10)
        {
            for (int j = 0; j < 9; j++)
                std::cout << rep->contact[i].first_name.at(j);
            std::cout << ".|";
        }
        else if (rep->contact[i].first_name.length() <= 10)
        {
            for (int j = 10; j - rep->contact[i].first_name.length(); j--)
                std::cout << " ";
            std::cout << rep->contact[i].first_name << "|";
        }

        if (rep->contact[i].last_name.length() > 10)
        {
            for (int j = 0; j < 9; j++)
                std::cout << rep->contact[i].last_name.at(j);
            std::cout << ".|";
        }
        else if (rep->contact[i].last_name.length() <= 10)
        {
            for (int j = 10; j - rep->contact[i].last_name.length(); j--)
                std::cout << " ";
            std::cout << rep->contact[i].last_name << "|";
        }

        if (rep->contact[i].nickname.length() > 10)
        {
            for (int j = 0; j < 9; j++)
                std::cout << rep->contact[i].nickname.at(j);
            std::cout << ".|";
        }
        else if (rep->contact[i].nickname.length() <= 10)
        {
            for (int j = 10; j - rep->contact[i].nickname.length(); j--)
                std::cout << " ";
            std::cout << rep->contact[i].nickname << "|";
        }
        i++;
        std::cout <<std::endl;
    }
    rep->print_contact(rep);
}

void    PhoneBook::print_contact(PhoneBook *rep)
{
    std::cout << std::endl << "Quel contact voulez-vous afficher ? Veuillez rentrez l'index du contact (entre 1 et 8)" << std::endl;
    std::string input("0");
    getline(std::cin, input);
    if (std::cin.eof())
        exit(1);
    int i = ft_atoi(input);
    std::cout << std::endl;
    if (i < 1 || i > 8)
        std::cout << "index invalide" << std::endl << std::endl;
    else
    {
        std::cout << "first name = " << rep->contact[i - 1].first_name << std::endl;
        std::cout << "last name = " << rep->contact[i - 1].last_name << std::endl;
        std::cout << "nickname = " << rep->contact[i - 1].nickname << std::endl;
        std::cout << "phone number = " << rep->contact[i - 1].phone_number << std::endl;
        std::cout << "darkest secret = " << rep->contact[i - 1].darkest_secret << std::endl << std::endl;
    }
}


