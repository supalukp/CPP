/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:28 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/05 16:54:33 by spunyapr         ###   ########.fr       */
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
        std::cerr << "Error: could not open file.\n";
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
        std::cerr << "Error: could not open file.\n";
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
        if (date.size() != 10)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date))
        {
            continue;
        }
        size_t res = value.find('.');
        float fValue;
        if (res != std::string::npos)
        {
            if (!isPosibleCharFloat(value))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            errno = 0;
            char *end;
            fValue = std::strtof(value.c_str(), &end);
            if (end == value.c_str() || errno == ERANGE || fValue < 1.0f || fValue > 1000.0f)
            {
                std::cerr << "Error: value out of range => " << line << std::endl;
                continue;
            }
        }
        else
        {
            if (!isAllDigit(value))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            errno = 0;
            char *end;
            long lValue = std::strtol(value.c_str(), &end, 10);
            if (end == value.c_str() || errno == ERANGE || lValue > 1000 || lValue < 1)
            {
                std::cerr << "Error: value out of range => " << line << std::endl;
                continue;
            }
            fValue = static_cast<float>(lValue);
        }
        
        std::map<std::string, double>::iterator it;
        it = _exchangeRates.find(date);
        if (it != _exchangeRates.end())
        {
            double newCal = fValue * it->second;
            std::cout << date << " => " << fValue << " = " << newCal << std::endl;
        }
        else 
        {
            it = _exchangeRates.lower_bound(date);
            if (it != _exchangeRates.begin())
                it--;
            double newCal = fValue * it->second;
            std::cout << date << " => " << fValue << " = " << newCal << std::endl;
        }
    }
    return (0);
}
