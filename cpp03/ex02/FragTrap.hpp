#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap(std::string name);
    FragTrap(FragTrap const & src);
    ~FragTrap(void);
    FragTrap &operator=(FragTrap const & src);

    void attack(const std::string& target);
    void highFivesGuys(void);
};