/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:22:20 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 11:45:09 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return (NULL);
	Zombie* zombies = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}
