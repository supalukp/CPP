/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:24:04 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 11:12:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void transform_cases(std::string input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] >= 97 && input[i] <= 122)
            std::cout << (char)(toupper(input[i]));
        else
            std::cout << input[i];
    }
}

int main(int ac, char *av[])
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        for(int i = 1; i < ac; i++)
        {
            transform_cases(av[i]);
        }
        std::cout << std::endl;
        
    }
    return (0);
}