/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:31:18 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/22 21:51:41 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int agrsErr(void)
{
    std::cout << "Wrong input: use ./harlFilter LEVEL" << std::endl;
    return (1);
}

int main (int ac, char *av[])
{
    Harl harl;

	if (ac != 2)
		return (agrsErr());
	harl.complain(av[1]);
    
	return (0);
}