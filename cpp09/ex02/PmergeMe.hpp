#pragma once

#include <iostream>
#include <algorithm>
#include <climits>
#include <deque>
#include <vector>
#include <ctime>

//extern int global;

// parsing
int doublon(const std::deque<int>& dek, int nb);
int doublon_vec(const std::vector<int>& tab, int nb);
int only_digit(char **av);
void parsing_ok(char **av, std::deque<int> *tab);
void parsing_ok_vec(char **av, std::vector<int> *tab);
void print_before_after(std::deque<int> tab);
void insertNumberOfJacob(std::vector<int> &Jacobsthal);

// algo avec deque
void mergeInsertSort(std::deque<int>& tab);
void mergeInsertionSort(std::deque<int>& deque);
void binarysearch(std::deque<int> &low, int element);

//algo avec vector
void mergeInsertionSort_vec(std::vector<int>& vector);
void mergeInsertSort_vec(std::vector<int>& tab);
void binarysearch_vec(std::vector<int> &low, int element);

