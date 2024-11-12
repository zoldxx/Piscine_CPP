#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character(void)
{
	for (int i = 0; i < 4; i++)
		this->inventaire[i] = NULL;
	std::cout << "Character Constructor called" << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventaire[i] = NULL;
	std::cout << "Character Constructor called" << std::endl;
}

Character::Character(Character const &src)
{
	for (int i = 0; i < 4; i++)
		this->inventaire[i] = NULL;
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "test" << std::endl;

		if (this->inventaire[i])
			delete this->inventaire[i];
		if (src.inventaire[i])
			this->inventaire[i] = src.inventaire[i]->clone();
		// if (!this->inventaire[i] && src.inventaire[i])
		// 	exit(1);
	}
	std::cout << "Character Copy constructor called" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventaire[i])
		{
			delete this->inventaire[i];
			this->inventaire[i] = NULL;
		}
	}
	std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(const Character &src)
{
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventaire[i])
			delete this->inventaire[i];
		if (src.inventaire[i])
			this->inventaire[i] = src.inventaire[i]->clone();
	}
	std::cout << "Character Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (i < 4 && this->inventaire[i])
		i++;
	if (i == 4)
		return ;
	if (m)
	this->inventaire[i] = m->clone();
}

void Character::use(int idx, ICharacter &target)
{
	int	i;

	i = 0;
	while (i < 4 && i != idx)
		i++;
	if (i == 4)
		return ;
	if (this->inventaire[i])
		this->inventaire[i]->use(target);
}

void Character::unequip(int idx)
{
	int	i;

	i = 0;
	while (i < 4 && i != idx)
		i++;
	if (i == 4)
		return ;
	if (this->inventaire[i])
    {
        delete this->inventaire[i];
        this->inventaire[i] = NULL;
    }
}

