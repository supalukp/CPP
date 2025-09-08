/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:37:36 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 21:05:15 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed(void) : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixed(other._fixed) {
	std::cout << "Copy constructor called" << std::endl;
	// *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixed = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const { 
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}


void Fixed::setRawBits(int const raw) {
	this->_fixed = raw;
}