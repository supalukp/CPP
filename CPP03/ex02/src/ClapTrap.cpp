/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:06 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 17:41:23 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
    : _name("Default"),
    _hitPoints(10), 
    _energyPoints(10), 
    _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap:: ClapTrap(std::string newName) 
    :_name(newName), 
    _hitPoints(10), 
    _energyPoints(10), 
    _attackDamage(0){
    std::cout   << newName << " : "
                << "ClapTrap constructor called with name" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap:: ~ClapTrap(void) {
    std::cout   << _name << " : " 
                << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        std::cout   << "ClapTrap " << _name 
                    << " attacks " << target 
                    << ", causing " << _attackDamage
                    << " points of damage" << std::endl;
    }
    else {
        std::cout   << "ClapTrap " << _name 
                    << " has no energy or is dead and cannot attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
        return ;
    }
    if (_hitPoints <= (int) amount)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! Now HP = " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount
                  << " Now HP = " << _hitPoints << std::endl;
    }
    else {
        std::cout   << "ClapTrap " << _name 
                    << " has no energy or is dead and cannot repair!" << std::endl;
    }
}
