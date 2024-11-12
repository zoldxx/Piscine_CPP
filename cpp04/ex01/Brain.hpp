#pragma once
#include <iostream>
#include <string.h>

class Brain
{
    public:
    Brain(void);
    Brain(Brain const & src);
    virtual ~Brain(void);
   Brain &operator=(Brain const & src);
   void put_ideas_in_brain(int i, std::string idea);
   std::string print_ideas(int i);

    protected:
    std::string ideas[100];
};