/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:40:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 14:38:06 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main (void)
{
	int size = 5;

	Zombie *zombies = zombieHorde(size, "Sunny");
	for(int i = 0; i < size; i++)
	{
		zombies[i].announce();
	}
	delete [] zombies;

	return (0);
}
