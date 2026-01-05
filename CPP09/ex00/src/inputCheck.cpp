/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:22:36 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/05 16:44:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


bool isPosibleCharFloat(const std::string& str)
{
    int dot = 0;
    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (str[i] == '.')
            dot++;
        else if (!std::isdigit(str[i])  && str[i] != '+')
        {
            return (false);
        }
        if (dot > 1)
            return (false);
    }
    return (true);
}

bool isAllDigit(const std::string& str)
{
    for(unsigned long i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

static bool isValidDateFormat(const std::string& date)
{
    if (date.size() != 10)
        return (false);

    if (date[4] != '-' || date[7] != '-')
        return (false);
        
    for (int i = 0; i < 10; i++) 
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return (false);
    }
    return (true);
}

static bool isValidDayInMonth(int month, int day, int year, const std::string& date)
{
    int thirtyOne[] = {1, 3, 5, 7, 8, 10, 12};
    int *begin = thirtyOne;
    int *end = begin + (sizeof(thirtyOne)/sizeof(thirtyOne[0]));
    int* it = std::find(begin, end, month);
    if (it != end)
    {
        if (day < 1 || day > 31)
        {
            std::cerr << "Error: date must be between (1-31) => " << date << std::endl;
            return (false);
        }
    }
    else if (month != 2 && (day < 1 || day > 30))
    {
        std::cerr << "Error: date must be between (1-30) => " << date << std::endl;
        return (false);
    }
    else if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        if (day < 1 || day > 29)
        {
            std::cerr << "Error: leap year date must be between (1-29) => " << date << std::endl;
            return (false);
        }
    }
    else
    {
        if (day < 1 || day > 28)
        {
            std::cerr << "Error: not leap year date must be between (1-28) => " << date << std::endl;
            return (false);
        }
    }
    return (true);
}

bool isValidDate(const std::string& date)
{
    if (!isValidDateFormat(date)) 
    {
        std::cerr << "Error: bad date format => " << date << std::endl;
        return (false);
    }
    
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009)
    {
        std::cerr << "Error: date before exist => " << date << std::endl;
        return (false);
    }
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: month not between(1-12) => " << date << std::endl;
        return (false);
    }
    if (!isValidDayInMonth(month, day, year, date))
        return (false);
    return (true);
}
