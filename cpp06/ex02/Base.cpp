#include "Base.hpp"

Base::~Base(void)
{
     std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
    Base *random;
    std::srand(std::time(0));
    int i = (std::rand() % 3) + 1;

    if (i == 1)
        return (random = new A());
    if (i == 2)
        return (random = new B());
    else
        return (random = new C());
}

void    identify(Base *p)
{
    std::cout << "identification by pointer : " << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "Object is Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object is Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object is Type C" << std::endl;
    else
        std::cerr << "Object is from unknowned type" << std::endl;
}

void    identify(Base& p)
{
    std::cout << "identification by reference : " << std::endl;
    Base check;
    try{
        check = dynamic_cast<A&>(p);
        std::cout << "Object is Type A" << std::endl;
        return ;
    }
    catch (std::exception &e){
        (void)e;
    }
    try{
        check = dynamic_cast<B&>(p);
        std::cout << "Object is Type B" << std::endl;
        return ;
    }
        catch (std::exception &e){
        (void)e;
    }
    try{
        check = dynamic_cast<C&>(p);
        std::cout << "Object is Type C" << std::endl;
        return ;
    }
        catch (std::exception &e){
        (void)e;
    }
    std::cerr << "Object is from unknowned type" << std::endl;
}