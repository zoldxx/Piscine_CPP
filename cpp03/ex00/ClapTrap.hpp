#include <iostream>
#include <string.h>

class ClapTrap
{
    public:
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap(void);
    ClapTrap &operator=(ClapTrap const & src);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    int getHP(void) const;
    int getEP(void) const;
    int getAD(void) const;

   // void setName(std::string const name);
    void setHP(int const hp);
    void setEP(int const ep);

    private :
    std::string _name;
    int _Hit_points;
    int _Energy_points;
    int _Attack_damage;
};