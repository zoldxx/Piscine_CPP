#include "PhoneBook.hpp"

int	ft_atoi(std::string nptr)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	if (nptr[i] != '\0')
		return (0);
	return (r * s);
}

int main(void)
{
    PhoneBook rep;
    std::string input("init");
    int i = 0;
    while (input != "EXIT")
    {
        std::cout << "Entrez une commande : ADD / SEARCH / EXIT" << std::endl;
        getline(std::cin, input);

        if (input == "ADD")
        {
            rep.add(&(rep.contact[i]));
            i++;
            if (i == 8)
                i = 0;
        }
        else if (input == "SEARCH")
            rep.search(&rep);

        else if (input == "EXIT")
            break;  
        else if (std::cin.eof())
            break ;
        else
            std::cout << "Commande invalide" << std::endl;
    }
    return 0;
}
