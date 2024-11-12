#include "Zombie.hpp"

int main(void)
{
    int nb = 3;

    Zombie *horde = zombieHorde(nb, "zombax");
    if (!horde)
        return (0);

    for (int i = 0; i < nb; i++)
        horde[i].announce();
    delete []horde;
    return (0);
}
