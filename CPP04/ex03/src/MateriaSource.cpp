/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:21:22 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/26 10:50:06 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for(int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
    _inventoryCount = 0;
    
    std::cout << "MateriaSource default constructor called" << std::endl;    
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for(int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    _inventoryCount = other._inventoryCount;
    
    // std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
    // std::cout << "MateriaSource copy assignment operator called" << std::endl;
    for(int i = 0; i < 4; i++)
            delete _inventory[i];
    _inventoryCount = 0;   
    
    for(int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    _inventoryCount = other._inventoryCount;
    return (*this);
}

MateriaSource::~MateriaSource(void) {
    for(int i = 0; i < 4; i++) {
        delete _inventory[i];
    }
    std::cout << "MateriaSource destructor called" << std::endl;   
}

void MateriaSource::learnMateria(AMateria *m) {
    if(!m)
        return ;
    for(int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            _inventoryCount++;
            return ;
        }
    }
    std::cout << "xx Cannot learn more than 4 materias xx" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    
    for(int i = 0; i < 4; i++) {
        if (_inventory[i] &&_inventory[i]->getType() == type) {
            std::cout << "Create Materia: " << type << std::endl;
            return (_inventory[i]->clone());
        }
    }
    std::cout << "Try to create Materia but type not found in inventory" << std::endl;
    return (NULL);
}
