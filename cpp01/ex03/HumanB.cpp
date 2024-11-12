#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {
    std::cout << "HumanB constructed" << std::endl;
	return;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB destructed" << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void)
{
    if (!(this->_weapon))
        std::cout << this->_name << " attacks with nothing " << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}