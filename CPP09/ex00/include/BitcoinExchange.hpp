/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:26 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/03 22:22:09 by spunyapr         ###   ########.fr       */
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
        // BitcoinExchange(const BitcoinExchange& other);
        // BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange(void);
        
        int loadData(const std::string& filename);
        int getInput(const std::string& filename);
};

#endif
