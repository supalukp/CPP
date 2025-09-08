/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 22:01:45 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &other): _x(other._x), _y(other._y) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Point::~Point(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed const& Point::getX(void) const{
	return (this->_x);
}

Fixed const& Point::getY(void) const {
	return (this->_y);
}
