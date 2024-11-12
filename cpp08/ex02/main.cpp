#include "MutantStack.hpp"

void	mainMutantStack(void)
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;
}

void mainListStack(void)
{
	std::list<int> liste;
	
	liste.push_back(5);
	liste.push_back(17);
	liste.push_back(3);
	liste.push_back(5);
	liste.push_back(737);
	liste.push_back(0);
	for (std::list<int>::iterator it = liste.begin(); it != liste.end(); ++it)
		std::cout << *it << std::endl;
}

int main(void)
{
	std::cout << "With my class MutantStack : " << std::endl;
	mainMutantStack();
	std::cout << "With the list container :" << std::endl;
	mainListStack();
	return 0;
}