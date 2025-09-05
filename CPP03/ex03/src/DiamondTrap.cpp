/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:50:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/06 00:10:55 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& diamondName) : ClapTrap(diamondName + "_clap_name"), FragTrap(diamondName), ScavTrap(diamondName) {
    this->name = diamondName;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout   << this->name << " : " 
                << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout   << this->name << " : " 
                << "DiamondTrap Destructor called" << std::endl;
}
        
void DiamondTrap::whoAmI() {
    std::cout   << "I am " << this->name 
                << " / " << ClapTrap::_name << std::endl;
}
