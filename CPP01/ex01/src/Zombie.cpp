/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:28:00 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 11:37:27 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void) 
{
	_name = "default";
	std::cout << _name << ": Created" << std::endl;
}

Zombie::Zombie(std::string newName)
{
	_name = newName;
	std::cout << _name << ": Created" << std::endl;
}
Zombie::~Zombie(void)
{
	std::cout << _name << ": Died" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
