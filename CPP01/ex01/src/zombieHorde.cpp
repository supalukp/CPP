/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:22:20 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 14:38:18 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombies = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}
