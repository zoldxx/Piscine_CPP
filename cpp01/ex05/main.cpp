#include "Harl.hpp"

int main(int ac, char **av) 
{

	Harl harl;
	
	if (ac == 2) {
		harl.complain(av[1]);
	}
	else {
		std::cout << "Harl only complains with a valid LEVEL entry.\n" << std::endl;
	}
	return 0;
}