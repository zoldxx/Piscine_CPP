#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

std::map<std::string, double> get_csv(void);
int good_date(std::string line);
int good_format(std::string line);
int good_number(std::string line);
int is_Bisextile(int year);
int valid_day(int &year, int &month, int &day);
int valid_date(std::string line);
void conversion(std::map<std::string, double> &csvMap, char *str);
void  print_conversion(std::string line, std::map<std::string, double> &csvMap);
