/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:50:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/10/08 08:10:35 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) 
    : ClapTrap("Default_clap_name"), 
        FragTrap(), 
        ScavTrap() 
{
    this->_name = "Default";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    
    std::cout   << this->_name << " : " 
                << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& diamondName) 
    : ClapTrap(diamondName + "_clap_name"), 
        FragTrap(diamondName), 
        ScavTrap(diamondName) 
{
    this->_name = diamondName;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout   << this->_name << " : " 
                << "DiamondTrap constructor called with name" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other),
        FragTrap(other), 
        ScavTrap(other) {
    *this = other;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap(void) {
    std::cout   << this->_name << " : " 
                << "DiamondTrap destructor called" << std::endl;
}
        
void DiamondTrap::whoAmI(void) {
    std::cout   << "I am " << this->_name 
                << " / " << ClapTrap::_name << std::endl;
}


void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
