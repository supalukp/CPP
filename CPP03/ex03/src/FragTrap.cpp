/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:40:37 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/10 15:44:52 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout   << _name << " : " 
                << "FragTrap constructor called" << std::endl;
}
FragTrap::~FragTrap(void) {
    std::cout   << _name << " : " 
                << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout   << "FragTrap " << _name 
                << " need a high fives !" << std::endl;
}
