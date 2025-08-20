/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:57:24 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 20:49:54 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <fstream>

int main (int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "Input: ./sed <filename> <string 1> <string 2 > \n";
        return (1);
    }
    std::ifstream ifs(av[1]);
    
}
