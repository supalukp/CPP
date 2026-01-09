/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:20:14 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/09 13:26:44 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isValidInput(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        int len = std::strlen(av[i]);
        if (len == 0)
            return (false);
        for (int j = 0; j < len; j++)
        {
            if (!isdigit(av[i][j]))
                return (false);
        }
        errno = 0;
        char *end;
        long value = std::strtol(av[i], &end, 10);
        if (end == av[i] || errno == ERANGE || value > INT_MAX || value < INT_MIN)
            return (false);
    }
    return (true);
}
