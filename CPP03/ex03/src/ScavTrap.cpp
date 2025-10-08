/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:44:30 by spunyapr          #+#    #+#             */
/*   Updated: 2025/10/08 08:10:05 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout   << _name << " : " 
                << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout   << _name << " : " 
                << "ScavTrap constructor called with name" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void) {
    std::cout   << _name << " : " 
                << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout   << "ScavTrap " << _name 
                    << " attacks " << target 
                    << ", causing " << _attackDamage
                    << " points of damage" << std::endl;
    }
    else {
        std::cout   << "ScavTrap " << _name 
                    << " has no energy or is dead and cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate( void ) {
    std::cout   << "ScavTrap " << _name 
                << " is now in Gate keeper mode" << std::endl;
}

