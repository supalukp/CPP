/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:11 by spunyapr          #+#    #+#             */
/*   Updated: 2026/03/26 13:59:23 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    // check input
    if (ac < 2)
        return (1);
    if (!isValidInput(ac, av))
    {
        std::cerr << "Error" << std::endl;   
        return (1);
    }
    // get input (push value in container)

    PmergeMe vec;

    for (int i = 1; i < ac; i++)
    {
        int value = std::atoi(av[i]);
        vec.addValueToMain(value);
    }

    vec.printMain();
    vec.orderPair();
    
    return (0);
}
