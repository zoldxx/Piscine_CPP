#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <climits>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    //container_type est un membre de std::stack qui donne accès au type de conteneur utilisé par std::stack
    //par défaut, std::stack utilise std::deque comme conteneur interne, et deque utilise des iterateurs
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}
    MutantStack& operator=(const MutantStack& other)
    {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
