/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:31 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/03 20:59:31 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
    {
        std::cerr << "Error: missing input file" << std::endl;
        return (1);
    }

    BitcoinExchange btc;
    if (btc.loadData("data.csv") == 1)
        return (1);
    if (btc.getInput(av[1]))
        return (1);
    
    return (0);
}
