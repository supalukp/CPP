/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:40:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 11:49:22 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
    // Positive Test
    std::cout << "\n************************************************\n";
    std::cout << "*          Test : Positive Number              *\n";
    std::cout << "************************************************\n\n";

    int size = 5;
    Zombie *zombies_pos = zombieHorde(size, "Sunny");
    for (int i = 0; i < size; i++)
        zombies_pos[i].announce();
    delete[] zombies_pos;

    // Negative Test
    std::cout << "\n************************************************\n";
    std::cout << "*          Test : Negative Number              *\n";
    std::cout << "************************************************\n\n";

    size = -5;
    Zombie *zombies_neg = zombieHorde(size, "Sunny");

    if (zombies_neg == NULL)
        std::cout << "zombies_neg = NULL" << std::endl;
    else
    {
        for (int i = 0; i < size; i++)
            zombies_neg[i].announce();
        delete[] zombies_neg;
    }

    // Zero Test
    std::cout << "\n************************************************\n";
    std::cout << "*              Test : Zero                     *\n";
    std::cout << "************************************************\n\n";

    size = 0;
    Zombie *zombies_zero = zombieHorde(size, "Sunny");

    if (zombies_zero == NULL)
        std::cout << "zombies_zero = NULL" << std::endl;
    else
    {
        for (int i = 0; i < size; i++)
            zombies_zero[i].announce();
        delete[] zombies_zero;
    }

    std::cout << std::endl;
    return 0;
}
