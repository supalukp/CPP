/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:56:23 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 11:46:09 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : _name(name), _weapon(weapon)
{
    std::cout << "HumanA created\n";
} 

HumanA::~HumanA(void)
{
    std::cout << "HumanA destroyed\n";
}

void HumanA::attack(void) const
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
