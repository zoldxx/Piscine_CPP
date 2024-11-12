#include "PmergeMe.hpp"

//int global = 0;

int main(int ac, char **av)
{
    if (ac < 3 || !only_digit(av))
        return (std::cout << "Error" << std::endl, 1);
    std::deque<int> dek;
    std::vector<int> vec;
    try
    {
        parsing_ok(av, &dek);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    try
    {
        parsing_ok_vec(av, &vec);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    print_before_after(dek);
    mergeInsertionSort(dek);
    mergeInsertionSort_vec(vec);

    //std::cout << std::endl << "global = " << global << std::endl;   
    //mergeInsertionSort_vec(vec, 2);
    return (0);
}
