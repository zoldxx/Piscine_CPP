#include "PmergeMe.hpp"

int doublon(const std::deque<int>& tab, int nb) 
{
    std::deque<int>::const_iterator it;
    for (it = tab.begin(); it != tab.end(); ++it)
    {
        if (*it == nb)
            return 1;
    }
    return 0;
}

int doublon_vec(const std::vector<int>& tab, int nb) 
{
    std::vector<int>::const_iterator it;
    for (it = tab.begin(); it != tab.end(); ++it)
    {
        if (*it == nb)
            return 1;
    }
    return 0;
}

int only_digit(char **av)
{
    int i = 1;
    int k = 0;

    while (av[i])
    {
        while (av[i][k])
        {
            if (!isdigit(av[i][k]))
                return (0);
            k++;
        }
        k = 0;
        i++;
    }
    return (1);
}

void parsing_ok(char **av, std::deque<int> *tab)
{
    int i = 1;
    char *endPtr;
    long int nb = 0;
    while (av[i])
    {
        nb = strtol(av[i], &endPtr, 10);
        if (endPtr == av[i])
            throw std::exception();
        if (nb < 0 || nb > INT_MAX)
            throw std::exception();
        if (doublon(*tab, nb))
            throw std::exception();
        tab->push_back(nb);
        i++;
    }
}

void parsing_ok_vec(char **av, std::vector<int> *tab)
{
    int i = 1;
    char *endPtr;
    long int nb = 0;
    while (av[i])
    {
        nb = strtol(av[i], &endPtr, 10);
        if (endPtr == av[i])
            throw std::exception();
        if (nb < 0 || nb > INT_MAX)
            throw std::exception();
        if (doublon_vec(*tab, nb))
            throw std::exception();
        tab->push_back(nb);
        i++;
    }
}

void print_before_after(std::deque<int> tab)
{
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = tab.begin(); it != tab.end(); it++)
        std::cout << *it << " ";
    
    std::deque<int> sorted = tab;
    std::sort(sorted.begin(), sorted.end());

    std::cout << std::endl << "After:  ";
    for (std::deque<int>::iterator it = sorted.begin(); it != sorted.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void	insertNumberOfJacob(std::vector<int> &Jacobsthal)
{
	Jacobsthal.push_back(0);
    Jacobsthal.push_back(1);
	Jacobsthal.push_back(3);
	Jacobsthal.push_back(5);
	Jacobsthal.push_back(11);
	Jacobsthal.push_back(21);
	Jacobsthal.push_back(43);
	Jacobsthal.push_back(85);
	Jacobsthal.push_back(171);
	Jacobsthal.push_back(341);
	Jacobsthal.push_back(683);
	Jacobsthal.push_back(1365);
	Jacobsthal.push_back(2731);
	Jacobsthal.push_back(5461);
	Jacobsthal.push_back(10923);
	Jacobsthal.push_back(21845);
	Jacobsthal.push_back(43691);
	Jacobsthal.push_back(87381);
	Jacobsthal.push_back(174763);
	Jacobsthal.push_back(349525);
	Jacobsthal.push_back(699051);
	Jacobsthal.push_back(1398101);
	Jacobsthal.push_back(2796203);
	Jacobsthal.push_back(5592405);
	Jacobsthal.push_back(11184811);
	Jacobsthal.push_back(22369621);
	Jacobsthal.push_back(44739243);
	Jacobsthal.push_back(89478485);
	Jacobsthal.push_back(178956971);
	Jacobsthal.push_back(357913941);
	Jacobsthal.push_back(715827883);
	Jacobsthal.push_back(1431655765);
	Jacobsthal.push_back(2147483647);
}

void    binarysearch(std::deque<int> &low, int element)
{
    int left = 0;
    int right = low.size() - 1;
    int middle;
    while (left <= right)
    {
        middle = left + ((right - left) / 2);
        if (element > low[middle])
            left = middle + 1;
        else
            right = middle - 1;
        //global++;
    }
    low.insert(low.begin() + left, element);
}


void mergeInsertSort(std::deque<int>& tab) 
{ 
    for (unsigned int i = 0; i < tab.size(); i += 2)
    {
        if (i + 1 == tab.size())
            break ;
        if (tab[i] > tab[i + 1])
        {
            std::swap(tab[i], tab[i + 1]);
            //global++;
        }
    }
    if (tab.size() > 2)
    {
        std::deque<int> low;
        for (unsigned int i = 0; i < tab.size(); i += 2)
            low.push_back(tab[i]);

        mergeInsertSort(low);

        std::deque<int> high;
        for (unsigned int i = 1; i < tab.size(); i += 2)
            high.push_back(tab[i]);
        
        std::vector<int> jacob;
        insertNumberOfJacob(jacob);

        int sizemax = high.size();
        int i = 0;
        int j = 1;
        int value_jacob;
        while (i < sizemax)
        {
            value_jacob = jacob[j] - 1;
            if (jacob[j] - 1 < sizemax) // si size est superieur au prochain nb jacob, on insere les nombres de high dans l'ordre decroissant a partir du palier de jacob
            {
                while (value_jacob > jacob[j - 1] - 1)
                {
                    binarysearch(low, high[value_jacob]);
                    value_jacob--;
                    i++;
                }
            }
            else // si size est inferieur au prochain nb jacob, on insere les nombres de high dans l'ordre decroissant et on s'arrete quand on arrive au nombre de jacob inferieur
            {
                int reverse_i = sizemax - 1;
                while (reverse_i > 0 && reverse_i != jacob[j - 1] - 1)
                {
                    binarysearch(low, high[reverse_i]);
                    reverse_i--;
                    i++;
                }
            }
            j++;
        }
        tab = low;
    }
}

void mergeInsertionSort(std::deque<int>& deque)
{
    timespec startTime, endTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    mergeInsertSort(deque);
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    long elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1000000000L + (endTime.tv_nsec - startTime.tv_nsec);
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque  : " << elapsedTime << " ns (nanosecondes)" << std::endl;
}

void    binarysearch_vec(std::vector<int> &low, int element)
{
    int left = 0;
    int right = low.size() - 1;
    int middle;
    while (left <= right)
    {
        middle = left + ((right - left) / 2);
        if (element > low[middle])
            left = middle + 1;
        else
            right = middle - 1;
        //global++;
    }
    low.insert(low.begin() + left, element);
}


void mergeInsertSort_vec(std::vector<int>& tab) 
{ 
    for (unsigned int i = 0; i < tab.size(); i += 2)
    {
        if (i + 1 == tab.size())
            break ;
        if (tab[i] > tab[i + 1])
        {
            std::swap(tab[i], tab[i + 1]);
            //global++;
        }
    }
    if (tab.size() > 2)
    {
        std::vector<int> low;
        for (unsigned int i = 0; i < tab.size(); i += 2)
            low.push_back(tab[i]);

        mergeInsertSort_vec(low);

        std::vector<int> high;
        for (unsigned int i = 1; i < tab.size(); i += 2)
            high.push_back(tab[i]);
        
        std::vector<int> jacob;
        insertNumberOfJacob(jacob);

        int sizemax = high.size();
        int i = 0;
        int j = 1;
        int value_jacob;
        while (i < sizemax)
        {
            value_jacob = jacob[j] - 1;
            if (jacob[j] - 1 < sizemax) // si size est superieur au prochain nb jacob, on insere les nombres de high dans l'ordre decroissant a partir du palier de jacob
            {
                while (value_jacob > jacob[j - 1] - 1)
                {
                    binarysearch_vec(low, high[value_jacob]);
                    value_jacob--;
                    i++;
                }
            }
            else // si size est inferieur au prochain nb jacob, on insere les nombres de high dans l'ordre decroissant et on s'arrete quand on arrive au nombre de jacob inferieur
            {
                int reverse_i = sizemax - 1;
                while (reverse_i > 0 && reverse_i != jacob[j - 1] - 1)
                {
                    binarysearch_vec(low, high[reverse_i]);
                    reverse_i--;
                    i++;
                }
            }
            j++;
        }
        tab = low;
    }
}

void mergeInsertionSort_vec(std::vector<int>& vector)
{
    timespec startTime, endTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    mergeInsertSort_vec(vector);
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    long elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1000000000L + (endTime.tv_nsec - startTime.tv_nsec);
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << elapsedTime << " ns (nanosecondes)" << std::endl;
}

// void mergeInsertSort(std::deque<int>& tab) 
// { 
//     for (unsigned int i = 0; i < tab.size(); i += 2)
//     {
//         if (i + 1 == tab.size())
//             break ;
//         if (tab[i] > tab[i + 1])
//         {
//             std::swap(tab[i], tab[i + 1]);
//             //global++;
//         }
//     }
//     if (tab.size() > 2)
//     {
//         std::deque<int> low;
//         for (unsigned int i = 0; i < tab.size(); i += 2)
//             low.push_back(tab[i]);

//         mergeInsertSort(low);

//         std::deque<int> high;
//         for (unsigned int i = 1; i < tab.size(); i += 2)
//             high.push_back(tab[i]);
        
//         std::vector<int> jacob;
//         insertNumberOfJacob(jacob);

//         int sizemax = high.size();
//         int i = 0;
//         while (i < sizemax)
//         {
//             binarysearch(low, high[i]);
//             i++;
//             tab = low;
//         }
//     }
// }



