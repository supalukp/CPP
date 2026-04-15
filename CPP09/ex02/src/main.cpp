/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:11 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/15 14:46:00 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    
    PmergeMe a;
    if (a.storeValidInput(ac, av) == 1)
        return (1);
    a.runFordJohnsonVector();
    a.printResult();
    
    return (0);
}
