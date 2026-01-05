/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:26 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/05 13:28:25 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm> 
#include <iomanip>
#include <ctime>

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

bool isValidInputFormat(const std::string& date, const std::string& value);
bool isValidDate(const std::string& date);

#endif
