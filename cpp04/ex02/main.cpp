#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal *troupeau[4];

	//Animal test;
	//Animal *test2 = new Animal;

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			troupeau[i] = new Dog();
		else
			troupeau[i] = new Cat();
	}
	troupeau[1]->put_ideas_in_brain(0, "i want to eat");
	troupeau[1]->put_ideas_in_brain(1, "i want to sleep");
	troupeau[3]->put_ideas_in_brain(0, "miam good milk");
	troupeau[3]->put_ideas_in_brain(1, "love this bed");

	std::cout << "cat 1 : " << troupeau[1]->print_ideas(0) << std::endl;
	std::cout << "cat 1 : " << troupeau[1]->print_ideas(1) << std::endl;
	std::cout << "cat 1 : " << troupeau[1]->print_ideas(2) << std::endl;

	std::cout << "cat 2 : " << troupeau[3]->print_ideas(0) << std::endl;
	std::cout << "cat 2 : " << troupeau[3]->print_ideas(1) << std::endl;
	std::cout << "cat 2 : " << troupeau[3]->print_ideas(2) << std::endl;
	troupeau[3]->makeSound();

	delete troupeau[1];
	troupeau[1] = troupeau[3];
	std::cout << "cat 1 copy cat 2" << std::endl;
	std::cout << "cat 1 after copy : " << troupeau[1]->print_ideas(0) << std::endl;
	std::cout << "cat 1 after copy : " << troupeau[1]->print_ideas(1) << std::endl;
	std::cout << "cat 1 after copy : " << troupeau[1]->print_ideas(2) << std::endl;

	troupeau[2]->put_ideas_in_brain(0, "i want to run");
	troupeau[2]->put_ideas_in_brain(1, "miam good bone");

	std::cout << "dog 1 : " << troupeau[2]->print_ideas(0) << std::endl;
	std::cout << "dog 1 : " << troupeau[2]->print_ideas(1) << std::endl;
	std::cout << "dog 1 : " << troupeau[2]->print_ideas(2) << std::endl;

	Animal *cop(troupeau[2]);

	std::cout << "a copy of dog 1 was created" << std::endl;

	std::cout << "copy of dog 1 : " << cop->print_ideas(0) << std::endl;
	std::cout << "copy of dog 1 : " << cop->print_ideas(1) << std::endl;
	std::cout << "copy of dog 1 : " << cop->print_ideas(2) << std::endl;

	Animal *cop2 = troupeau[2];
	std::cout << "another copy of dog 1 was created" << std::endl;


	std::cout << "other copy of dog 1 : " << cop2->print_ideas(0) << std::endl;
	std::cout << "other copy of dog 1 : " << cop2->print_ideas(1) << std::endl;
	std::cout << "other copy of dog 1 : " << cop2->print_ideas(2) << std::endl;

	for (int i = 0; i < 3; i++)
		delete troupeau[i];
	return (1);
}

// int main(void)
// {
// 	Cat basic;

// 	basic.put_ideas_in_brain(0, "aa");
// 	basic.put_ideas_in_brain(1, "ee");
// 	std::cout << basic.print_ideas(0) << std::endl;
// 	std::cout << basic.print_ideas(1) << std::endl;
// 	{
// 	Cat tmp = basic;
// 	std::cout << tmp.print_ideas(0) << std::endl;
// 	std::cout << tmp.print_ideas(1) << std::endl;
// 	}
// 	std::cout << basic.print_ideas(0) << std::endl;
// 	std::cout << basic.print_ideas(1) << std::endl;

// 	return (0);
// }

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// return 0;
// }
