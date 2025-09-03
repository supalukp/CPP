/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/03 15:35:02 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point( float const x, float const y ) {
	std::cout << "Float constructor called" << std::endl;
}

Point::Point( const Point &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Point& Point::operator=( const Point& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~Point();
		new (this) Point(other);
	}
	return (*this);
}

Point::~Point( void ) {
	std::cout << "Destructor called" << std::endl;
}
