#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include <iostream>
#include <string>
#include <stdlib.h>


#include "Contact.hpp"

class PhoneBook
{
    public:

    void add(Contact *pb);
    void search(PhoneBook *rep);
    void print_contact(PhoneBook *rep);

    Contact contact[8];
};

int	ft_atoi(std::string nptr);


#endif