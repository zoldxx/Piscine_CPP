#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T >
int   easyfind(T tab, int x)
{
  std::vector<int>::iterator it = find (tab.begin(), tab.end(), x);
  if (it != tab.end())
  {
    std::cout << "Element \"" << x << "\" found in tab at position " << std::distance(tab.begin(), it) <<std::endl;
    return (0);
  }
  else
  {
    std::cout << "Element \"" << x << "\" not found in tab" <<std::endl;
    return (1);
  }
}

