/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:04:05 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/10 16:31:33 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("default") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string newType) : _type(newType) {
    std::cout   << newType << " : "
                << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal(void) {
    std::cout   << _type << " : " 
                << "Animal Destructor called" << std::endl;
}

std::string const& Animal::getType( void ) const { return (_type); }
