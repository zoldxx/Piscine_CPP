#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <climits>

class Span
{
  public:
  Span(unsigned int N);
  ~Span(void);
  Span(Span const & src);
  Span &operator=(Span const &src);

  long shortestSpan(void);
  long longestSpan(void);
  void addNumber(int x);
  void addNumbers(unsigned int x);
  void print_values(void);

  private:
  std::vector<int> tab;
  unsigned int size;
  unsigned int i;
};

