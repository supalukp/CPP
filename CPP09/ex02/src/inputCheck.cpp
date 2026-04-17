/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:20:14 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/17 10:29:05 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstring> 
#include <cstdlib>
#include <iostream>
#include <errno.h>

bool isValidInput(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        int len = std::strlen(av[i]);
        if (len == 0)
        {
            std::cerr << "Error: invalid input '" << av[i] << "' : empty" << std::endl;
            return (false);
        }
        for (int j = 0; j < len; j++)
        {
            if (!isdigit(av[i][j]))
            {
                std::cerr << "Error: invalid input '" << av[i] << "'" << std::endl;
                return (false);
            }
        }
        errno = 0;
        char *end;
        long value = std::strtol(av[i], &end, 10);
        if (end == av[i] || errno == ERANGE || value > INT_MAX || value < INT_MIN)
        {
            std::cerr << "Error: invalid input '" << av[i] << "'" << std::endl;
            return (false);
        }
    }
    return (true);
}
