/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:11 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/09 20:08:08 by spunyapr         ###   ########.fr       */
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
    // std::vector<int> test = buildBlocks(11, 2);
    // for (size_t i = 0; i < test.size(); i++)
    // {
    //     std::cout << "--------------------------" << std::endl;
    //     std::cout << i << ": " << test[i] << std::endl;
    // }
    return (0);
}
