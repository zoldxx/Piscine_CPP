#include "BitcoinExchange.hpp"

std::map<std::string, double> get_csv(void)
{
    std::map<std::string, double> csvMap;
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::exception();
    std::string line;
    std::string key;
    std::string value_str;
    double value;
    while (std::getline(file, line)) 
    {
        key = line.substr(0, 10);
        value_str = line.substr(11, 100);
        char* endptr;
        value = strtod(value_str.c_str(), &endptr);
        csvMap[key] = value;
    }
    return (csvMap);
}

int good_date(std::string line)
{
    int i = 0;
    while (i < 4)
    {
        if (!isdigit(line[i]))
            return (0);
        i++;
    }
    if (line[i] != '-')
        return (0);
    i++;
    while (i < 7)
    {
        if (!isdigit(line[i]))
            return (0);
        i++;
    }
    if (line[i] != '-')
        return (0);
    i++;
    while (i < 10)
    {
        if (!isdigit(line[i]))
            return (0);
        i++;
    }
    if (line[i] == ' ' && line[i + 1] == '|')
        return (1);
    else 
        return (0);
}

int good_format(std::string line)
{
    if (line.size() < 12 || !good_date(line))
        return (0);
    size_t pos = line.find("|");
    pos++;
    if (line[pos] != ' ')
        return (0);
    pos++;
    if (line[pos] == '-')
        pos++;
    if (!isdigit(line[pos]))
        return (0);
    while (isdigit(line[pos]))
        pos++;
    if (line[pos] && line[pos] != '\n' && line[pos] != '.')
        return (0);
    if (line[pos] == '.')
        pos++;
    while (line[pos] && line[pos] != '\n')
    {
        if (!isdigit(line[pos]))
            return (0);
        pos++;
    }
    return (1);
}

int good_number(std::string line)
{
    size_t pos = line.find("|");
    pos++;
    std::string value_str = line.substr(pos, 100);
    char* endptr;
    double value = strtod(value_str.c_str(), &endptr);
    if (endptr == value_str.c_str())
        return (0);
    if (value < 0.0)
        return (std::cout << "Error: not a positive number." << std::endl, 0);
    if (value > 1000.0)
        return (std::cout << "Error: too large a number." << std::endl, 0);
    return (1); 
}

int is_Bisextile(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int valid_day(int &year, int &month, int &day)
{
    if (month == 0 || day == 0)
        return (0);
    if (month == 1 && day > 31)
        return (0);
    if ((month == 2 && is_Bisextile(year) && day > 29) || (month == 2 && !is_Bisextile(year) && day > 28))
        return (0);
    if (month == 3 && day > 31)
        return (0);
    if (month == 4 && day > 30)
        return (0);
    if (month == 5 && day > 31)
        return (0);
    if (month == 6 && day > 30)
        return (0);
    if (month == 7 && day > 31)
        return (0);
    if (month == 8 && day > 31)
        return (0);
    if (month == 9 && day > 30)
        return (0);
    if (month == 10 && day > 31)
        return (0);
    if (month == 11 && day > 30)
        return (0);
    if (month == 12 && day > 31)
        return (0);
    return (1);
}

int valid_date(std::string line)
{
    std::string date = line.substr(0, 10);
     if (line.compare("2009-01-02") < 0)
        return (std::cout << "Error: date too old." << std::endl, 0);

    std::string sub_year = line.substr(0, 4);
    std::string sub_month = line.substr(5, 2);
    std::string sub_day = line.substr(8, 2);

    int year = std::atoi(sub_year.c_str());
    int month = std::atoi(sub_month.c_str());
    int day = std::atoi(sub_day.c_str());

    if (month > 12 || !valid_day(year, month, day))
        return (std::cout << "Error: not a valid date." << std::endl, 0);  
    return (1);
}

void  print_conversion(std::string line, std::map<std::string, double> &csvMap)
{
    std::string date = line.substr(0, 10);
    std::map<std::string, double>::iterator it;
    it = csvMap.begin();
    while (date.compare(it->first) >= 0)
        it++;
    if (it != csvMap.begin())
    it--;
    std::string value_str = line.substr(13, 100);
    char* endptr;
    double value = strtod(value_str.c_str(), &endptr);
    std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

void conversion(std::map<std::string, double> &csvMap, char *str)
{
    (void) csvMap;
    std::ifstream file(str);
    if (!file.is_open())
        throw std::exception();
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
    {
        std::cout << "Error: Invalid header" << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        if (!good_format(line))
            std::cout << "Error: bad input => " << line << std::endl;
        else if (!good_number(line))
            ;
        else if (!valid_date(line))
            ;
        else
            print_conversion(line, csvMap);
    }
}