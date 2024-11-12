#include "Array.hpp"

int main(void)
{

    int * a = new int();
    std::cout << "display a : " << *a << std::endl;
    delete a;
    std::cout << "\ntest with int : " << std::endl;
    Array<int> empty_int;
    Array<int> a_int(5);
    for (unsigned int i = 0; i < a_int.size(); i++)
        a_int.modify_val(i, i);
    std::cout << "a_int after modification of values : " << std::endl;
    for (unsigned int i = 0; i < a_int.size(); i++)
        a_int.print_val(i); 

    empty_int = a_int;
    std::cout << "empty_int after copy assignment : " << std::endl;
    for (unsigned int i = 0; i < empty_int.size(); i++)
        empty_int.print_val(i);
    for (unsigned int i = 0; i < a_int.size(); i++)
        a_int.modify_val(i, i + 2);
    std::cout << "a_int after modification of values : " << std::endl;
    for (unsigned int i = 0; i < a_int.size(); i++)
        a_int.print_val(i);

    std::cout << "empty_int haven't been affected by modification of a_int : " << std::endl;
    for (unsigned int i = 0; i < empty_int.size(); i++)
        empty_int.print_val(i);      
    a_int.~Array();
     std::cout << "empty_int haven't been affected by destruction of a_int : " << std::endl;
    for (unsigned int i = 0; i < empty_int.size(); i++)
        empty_int.print_val(i);


    std::cout << "\n\ntest with strings : " << std::endl;
    Array<std::string> a_str(5);
    for (unsigned int i = 0; i < a_str.size(); i++)
        a_str.modify_val(i, "salut");
    std::cout << "a_str after modification of values : " << std::endl;
    for (unsigned int i = 0; i < a_str.size(); i++)
        a_str.print_val(i); 

    Array<std::string> empty_str(a_str);
    std::cout << "empty_str after construction by copy : " << std::endl;
    for (unsigned int i = 0; i < empty_str.size(); i++)
        empty_str.print_val(i);
    for (unsigned int i = 0; i < a_str.size(); i++)
        a_str.modify_val(i, "yo");
    std::cout << "a_str after modification of values : " << std::endl;
    for (unsigned int i = 0; i < a_str.size(); i++)
        a_str.print_val(i);

    std::cout << "empty_str haven't been affected by modification of a_str : " << std::endl;
    for (unsigned int i = 0; i < empty_str.size(); i++)
        empty_str.print_val(i);      
    a_str.~Array();
     std::cout << "empty_str haven't been affected by destruction of a_str : " << std::endl;
    for (unsigned int i = 0; i < empty_str.size(); i++)
        empty_str.print_val(i);

    empty_str[2] = "test";
    std::cout << "access with [] operators : " << empty_str[2] << std::endl;
    try
    {
       empty_str[8] = "test8";
    }
    catch (std::exception &e)
    {
         std::cout << "index out of bounds" << std::endl;
    }
    try
    {
        std::cout << "access with [] operators : " << empty_str[8] << std::endl;
    }
    catch (std::exception &e)
    {
         std::cout << "index out of bounds" << std::endl;
    }
    return (0);
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
