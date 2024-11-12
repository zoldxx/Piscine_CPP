#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac == 1)
          std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

    else if (ac > 1)
    {
        std::string str = av[1];
        std::string dest;

        int i = 2;
        while (av[i])
            str = str + " " + av[i++];

        dest = str;
        int taille = str.length();
        i = 0;

        while (i < taille)
        {
             dest.at(i) = std::toupper(str.at(i));
             i++;
        }
        std::cout << dest << std::endl;
    }  
    return 0;
}