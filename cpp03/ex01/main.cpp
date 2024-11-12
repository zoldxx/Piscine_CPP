#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main(void)
{
    ScavTrap scar("brrrr");

    scar.attack("ennemy");
    scar.beRepaired(12);
    std::cout << std::endl << "scavtrap have " << scar.getHP() << " hit points and " << scar.getEP() << " energy points now" << std::endl;
    scar.guardGate();
    return (0);
}

// int main(void)
// {
//     ClapTrap war("warrior");
//     ClapTrap wiz("wizard");
//     ClapTrap copy(war);

//     war.attack("wizard");
//     wiz.takeDamage(6);
//     wiz.beRepaired(4);
//     wiz.attack("warrior");
//     war.takeDamage(5);
//     std::cout << std::endl << "warrior have " << war.getHP() << " hit points and " << war.getEP() << " energy points now" << std::endl;
//     std::cout << "wizzard have " << wiz.getHP() << " hit points and " << wiz.getEP() << " energy points now" << std::endl;
//     std::cout << "copy have " << copy.getHP() << " hit points and " << copy.getEP() << " energy points now" << std::endl;
//     std::cout << "copy copies the wizard !" << std::endl;
//     copy = wiz;
//     std::cout << "copy have " << copy.getHP() << " hit points and " << copy.getEP() << " energy points now" << std::endl << std::endl;
//     for (int i = 0; i < 10; i++)
//         war.attack("wizzard");
//     std::cout << std::endl;
//     wiz.takeDamage(11);
//     wiz.beRepaired(3);
//     return (0);
// }