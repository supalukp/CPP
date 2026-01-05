/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:22:36 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/05 13:31:22 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidInputFormat(const std::string& date, const std::string& value)
{
    if (date.size() != 10)
    {
        return (false);
    }
    for (unsigned long i = 0; i < value.size(); i++)
    {
        if (!std::isdigit(value[i]))
        {
            return (false);
        }
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

bool isValidDate(const std::string& date)
{
    // check date format 0000-00-00
    if (!isValidDateFormat(date)) 
    {
        std::cerr << "Error: bad date format => " << date << std::endl;
        return (false);
    }
    
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
    (void)day;

    
    // check year from 2009
    if (year < 2009)
    {
        std::cerr << "Error: date before exist => " << date << std::endl;
        return (false);
    }
    // check month 01-12
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: month not between(1-12) => " << date << std::endl;
        return (false);
    }
    // check date (depend on month & leap year)
    
    // check current date
    
    // std::time_t now = std::time(NULL);
    // std::tm *ltm = std::localtime(&now);
    // int currentYear = 1900 + ltm->tm_year;
    // if (year > currentYear)
    // {
    //     std::cerr << "Error: future date => " << date << std::endl;
    //     return (false);
    // }
    return (true);
}
