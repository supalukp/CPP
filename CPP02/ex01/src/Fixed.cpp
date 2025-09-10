/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:37:36 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/10 13:18:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed() : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int newValue) {
	_fixed = newValue << _fractionBit;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float newValue) {
	_fixed = (int)(roundf(newValue * (1 << _fractionBit)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixed(other._fixed) {
	std::cout << "Copy constructor called" << std::endl;
	// *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixed = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const { 
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw) {
	this->_fixed = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)(_fixed) / (float)(1 << _fractionBit));
}

int		Fixed::toInt( void ) const {
	return (int)(_fixed >> _fractionBit);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Fixed& num) {
	out << num.toFloat();
	return (out);
}
