/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:02:18 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/17 21:07:45 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default") {
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type) {
    std::cout << "AMateria constructor called with type" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
    // std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    // std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria(void) {
    std::cout   << _type << " : " 
                << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const {
    return (_type);
}
