#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void ) {
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* x = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();
	WrongCat ww;

	x->makeSound();
	w->makeSound();
	ww.makeSound();
	std::cout << x->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;

	delete meta;
	delete j;
	delete i;
	delete x;
	delete w;

	return 0;
	
}