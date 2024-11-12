#include "Serializer.hpp"

int main(void)
{
	Data test;

	std::cout << "test value :" << test.get_i() << std::endl;
	test.set_i(75);
	std::cout << "test value change:" << test.get_i() << std::endl;
	std::cout << "test adress : " << &test << std::endl;

	Serializer *s = NULL;
	uintptr_t a = s->serialize(&test);
	Data *ptr = s->deserialize(a);

	std::cout << "test adress : " << &test << "   ptr : " << ptr << std::endl;
	std::cout << "test value with ptr : " << ptr->get_i() << std::endl;
	ptr->set_i(98);
	std::cout << "test value with ptr : " << ptr->get_i() << std::endl;
	std::cout << "test value :" << test.get_i() << std::endl;
}