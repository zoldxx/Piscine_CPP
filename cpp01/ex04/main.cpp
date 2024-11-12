#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
         std::cout << "Wrong numbers of arguments" << std::endl;
         return (0);
    }
    std::string filename = av[1];
    std::string src = av[2];
    std::string dest = av[3];
    std::string line;
    std::string contenu;

    std::ifstream input(filename);
    if (!input)
    {
        std::cout << "fail opening file" << std::endl;
        return (0);
    }
    while(getline(input, line))
    {
        contenu += line;
        contenu += '\n';   
    }
    if (contenu[0] && contenu[1])
        contenu.pop_back();
    else
        return (0);

    std::string new_contenu;
    std::string tmp;
    std::size_t found;
    std::size_t pos = 0;
    found = contenu.find(src);
    while (found != std::string::npos)
    {
        tmp.assign(contenu, pos, found - pos);
        new_contenu += tmp;
        new_contenu += dest;
        pos += (tmp.size() + src.size());
        found = contenu.find(src, pos);
    }
    tmp.assign(contenu, pos, found);
    new_contenu += tmp;

    std::ofstream output(filename + ".replace");
    if (!output)
    {
        std::cout << "fail creating output" << std::endl;
        return (0);
    }
    output << new_contenu ;
    return (0);
}
