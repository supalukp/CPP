/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:08:02 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/06 16:11:34 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: usage ./RPN \"postfix notation(ex. 3 4 + 2 *)\"" << std::endl;
        return (1);
    }
    RPN res;
    try
    {
        res.evalRPN(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: "<< e.what() << std::endl;
        return (1);
    }

    return (0);
}
