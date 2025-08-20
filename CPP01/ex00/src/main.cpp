/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:40:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 13:19:34 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie a("A");
	Zombie *b = newZombie("B");
	
	a.announce();
	b->announce();
	randomChump("C");
	
	delete b;
	
	return (0);
}
