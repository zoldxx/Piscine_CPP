#include "BitcoinExchange.hpp"

int main(int ac, char **av) 
{
    (void) av;
    if (ac != 2)
        return (std::cout << "wrong numbers of arguments" << std::endl, 1);
    std::map<std::string, double> csvMap;
    try
    {
        csvMap = get_csv();
    }
    catch (std::exception & e)
    {
        std::cerr << "Can't open the CSV file." << std::endl;
        return 1;
    }
    try
    {
        conversion(csvMap, av[1]);
    }
    catch (std::exception & e)
    {
        std::cerr << "Can't open the file " << av[1] << std::endl;
        return 1;
    }
    return (0);
}
