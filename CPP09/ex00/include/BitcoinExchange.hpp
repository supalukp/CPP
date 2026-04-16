/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:26 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/16 14:14:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
// #include <iostream>
// #include <fstream>
#include <string>
// #include <algorithm> 
// #include <cerrno>

class BitcoinExchange 
{
    private:
        std::map<std::string, double> _exchangeRates;
        
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange(void);
        
        int loadData(const std::string& filename);
        int getInput(const std::string& filename);
        
};

bool isValidDate(const std::string& date);
bool isAllDigit(const std::string& str);
bool isPosibleCharFloat(const std::string& str);

#endif
