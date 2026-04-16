/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:11 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/16 11:27:39 by spunyapr         ###   ########.fr       */
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
    
    clock_t v_start = clock();
    a.runFordJohnsonVector();
    clock_t v_end = clock();
    
    clock_t d_start = clock();
    a.runFordJohnsonDeque();
    clock_t d_end = clock();
    
    a.printResult(v_end - v_start, d_end - d_start);

    // std::cout << "\nTest: Copy constructor" << std::endl;
    // PmergeMe b(a);
    // b.printResult(v_end - v_start, d_end - d_start);
    
    // std::cout << "\nTest: Copy assignment operator" << std::endl;
    // PmergeMe c;
    // c = b;
    // c.printResult(v_end - v_start, d_end - d_start);
    
    return (0);
}
