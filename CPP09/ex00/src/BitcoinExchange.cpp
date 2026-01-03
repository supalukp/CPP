/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:28 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/03 22:45:38 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
// {
//     if (this )
// }

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
// {

// }

BitcoinExchange::~BitcoinExchange(void) { }

int BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream infile;
    
    infile.open(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: opening infile\n";
        return (1);
    }
    std::string line;
    bool firstline = true;
    while (std::getline(infile, line))
    {
        if (firstline)
        {
            firstline = false;
            continue;
        }
        if (line.empty())
            continue;
        size_t index = line.find(',');
        if (index == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date  = line.substr(0, index);
        std::string value = line.substr(index + 1);
        
        double dValue = atof(value.c_str());
        _exchangeRates.insert(std::pair<std::string, double>(date, dValue));
    }
    infile.close();
    return (0);
}

static bool badDateFormat(const std::string& date)
{
    if (date.size() != 10)
        return (true);

    if (date[4] != '-' || date[7] != '-')
        return (true);
        
    for (int i = 0; i < 10; i++) 
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return (true);
    }
    return (false);
}

static bool checkDate(const std::string& date)
{
    // check date format 0000-00-00
    if (badDateFormat(date)) 
    {
        std::cerr << "Error: bad date format => " << date << std::endl;
        return (false);
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    // check year from 2009
    if (year < 2009)
    {
        std::cerr << "Error: date before exist => " << date << std::endl;
        return (false);
    }
    // check current date
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    if (year > currentYear)
    {
        std::cerr << "Error: future date => " << date << std::endl;
        return (false);
    }
    // check month 01-12
    if (month < 1 || month > 12)
    {
        std::cerr << "Error: month not between(1-12) => " << date << std::endl;
        return (false);
    }
    std::cout << month << day << std::endl;
    // check date (depend on month & leap year)
    
    return (true);
}

int BitcoinExchange::getInput(const std::string& filename)
{
    std::ifstream infile;
    
    infile.open(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: opening infile\n";
        return (1);
    }
    std::string line;
    bool firstline = true;
    while (std::getline(infile, line))
    {
        if (firstline)
        {
            firstline = false;
            continue;
        }
        if (line.empty())
            continue;
        size_t index = line.find('|');
        if (index == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date  = line.substr(0, index-1);
        // check date 
        if (checkDate(date) == false)
        {
            continue;
        }
        std::string value = line.substr(index + 1);
        // check value
        double dValue = atof(value.c_str());
        
        // calculate
        std::map<std::string, double>::iterator it;
        it = _exchangeRates.find(date);
        if (it != _exchangeRates.end())
        {
            double newCal = dValue * it->second;
            std::cout << date << " => " << dValue << " = " << newCal << std::endl;
        }
        else 
        {
            it = _exchangeRates.lower_bound(date);
            if (it != _exchangeRates.begin())
                it--;
            double newCal = dValue * it->second;
            std::cout << date << " => " << dValue << " = " << newCal << std::endl;
        }
    }
    return (0);
}
