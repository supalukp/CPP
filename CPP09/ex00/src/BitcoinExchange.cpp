/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:28 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/05 13:25:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->_exchangeRates = other._exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if(this != &other)
    {
        this->_exchangeRates = other._exchangeRates;
    }
    return (*this);
}

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
        std::string date  = line.substr(0, index - 1);
        std::string value = line.substr(index + 2);
        if (!isValidInputFormat(date, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        // check date 
        if (!isValidDate(date))
        {
            continue;
        }
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
