/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:37:36 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/04 15:55:21 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionBit = 8;

Fixed::Fixed() : _fixed(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int newValue) {
	_fixed = newValue << _fractionBit;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float newValue) {
	_fixed = (int)(roundf(newValue * (1 << _fractionBit)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
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
	return ((float)(_fixed)/ (1 << _fractionBit));
}

int		Fixed::toInt( void ) const {
	return (_fixed >> _fractionBit);
}

std::ostream& operator <<(std::ostream &out, const Fixed& num) {
	out << num.toFloat();
	return (out);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator<(const Fixed& other){
	return getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) {
	return getRawBits() > other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) {
	return getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) {
	return getRawBits() <= other.getRawBits();
}
bool Fixed::operator==(const Fixed& other) {
	return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) {
	return getRawBits() != other.getRawBits();
}

Fixed operator+(Fixed x, Fixed const& y) {
	Fixed result;
    result.setRawBits(x.getRawBits() + y.getRawBits());
	return (result);
}

Fixed operator-(Fixed x, Fixed const& y) {
	Fixed result;
    result.setRawBits(x.getRawBits() - y.getRawBits());
	return (result);
}

Fixed operator*(Fixed x, Fixed const& y) {
	Fixed result;
	long tmp = (long)x._fixed * (long)y._fixed;
	result.setRawBits(tmp >> Fixed::_fractionBit);
	return (result);
}

Fixed operator/(Fixed x, Fixed const& y) {
	Fixed result;
	long tmp = (long)x._fixed / (long)y._fixed;
    result.setRawBits(tmp >> Fixed::_fractionBit);
	return (result);
}

Fixed Fixed::operator++() {
	this->_fixed += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixed += 1;
	return (temp);
}

Fixed Fixed::operator--() {
	this->_fixed -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixed -= 1;
	return (temp);
}

Fixed& Fixed::min(Fixed& x, Fixed& y) {
	if (x.getRawBits() < y.getRawBits())
		return (x);
	return (y);
}

const Fixed& Fixed::min(Fixed const& x, Fixed const& y) {
	if (x.getRawBits() < y.getRawBits())
		return (x);
	return (y);
}

Fixed& Fixed::max(Fixed& x, Fixed& y) {
	if (x.getRawBits() > y.getRawBits())
		return (x);
	return (y);
}

const Fixed& Fixed::max(Fixed const& x, Fixed const& y) {
	if (x.getRawBits() > y.getRawBits())
		return (x);
	return (y);
}
