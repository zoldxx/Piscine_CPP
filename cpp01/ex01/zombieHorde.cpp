#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    int i = 0;

    Zombie *horde;
    horde = new (std::nothrow) Zombie[N];
    if (!horde)
        return (NULL);
    while (i < N)
    {
        horde[i].set_name(name);
        i++;
    }
    return (horde);
}
