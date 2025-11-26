/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:18:46 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/21 12:29:30 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name("default") {
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
        
    for (int i = 0; i < MAX_FLOOR; i++)
        _floor[i] = NULL;
    _floorCount = 0;
    
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string newName) : _name(newName) {
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < MAX_FLOOR; i++)
        _floor[i] = NULL;
    _floorCount = 0;
    
    std::cout << "Character constructor called with name" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
    for(int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }

    for (int i = 0; i < MAX_FLOOR; i++) {
        if (i < other._floorCount && other._floor[i])
            _floor[i] = other._floor[i]->clone();
        else
            _floor[i] = NULL;
    }
    _floorCount = other._floorCount;
    
    // std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    // std::cout << "Character copy assignment operator called" << std::endl;
    if(this != &other) 
    {
        for(int i = 0; i < 4; i++)
            delete _inventory[i];
            
        for(int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
        _name = other._name;
        
        for (int i = 0; i < MAX_FLOOR; i++) {
            delete _floor[i];
            _floor[i] = NULL;
        }
        _floorCount = 0;

        for (int i = 0; i < other._floorCount; i++) {
            _floor[i] = other._floor[i]->clone();
        }
        _floorCount = other._floorCount;
    }
    return (*this);
}

Character::~Character(void) {
    std::cout << "Character destructor called" << std::endl;
    for(int i = 0; i < 4; i++) { 
        delete _inventory[i];
    }

    for (int i = 0; i < _floorCount; i++) {
        delete _floor[i];
    }
}

std::string const& Character::getName() const {
    return (_name);
}

void Character::equip(AMateria* m) {
    if (!m)
        return ;
    for(int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            std::cout << "++ Equipped Materia: " << m->getType() << " in slot " << i << std::endl;
            return ;
        }
    }
    std::cout << "xx Cannot equip Materia: " << m->getType() << " (inventory full) xx" << std::endl;
    delete m;   
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3 || !_inventory[idx])
        return ;
    if (_floorCount >= MAX_FLOOR) {
        std::cout << "Floor is full, can not unequip" << std::endl;
        return ;
    }
    std::cout << "-- Unequip Materia: " << _inventory[idx]->getType() << std::endl;
    _floor[_floorCount++] = _inventory[idx];
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) {
        std::cout << _name << " tried to use invalid index " << idx << "." << std::endl;
        return;
    }
    if (_inventory[idx] == NULL) {
        std::cout << _name << " has no materia in slot " << idx << " to use." << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}
