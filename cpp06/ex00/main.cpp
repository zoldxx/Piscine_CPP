#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		 std::cout << "This program takes only one argument" << std::endl;
		 return (0);
	}
	std::string str = av[1];
	ScalarConverter *conv = NULL;
	conv->convert(str);
    return (0);
}

// int main(void)
// {
//     float f = static_cast<float>(INT_MAX);
//         std::cout << f << std::endl;
//     return (0);
// }
