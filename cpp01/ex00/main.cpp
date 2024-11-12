#include "Zombie.hpp"

int main(void)
{
    Zombie *zomba;

    zomba = newZombie("zombinho");
    zomba->announce();
    randomChump("Bizon le zombie");
    delete zomba;
    return (0);
}
