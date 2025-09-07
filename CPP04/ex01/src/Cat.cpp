/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/07 23:38:04 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    _catBrain = new Brain;
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) 
    : Animal(other) , _catBrain(new Brain(*other._catBrain)){
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
        delete this->_catBrain;
        this->_catBrain = new Brain(*other._catBrain);
	}
	return (*this);
}

Cat::~Cat( void ) {
    delete _catBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound( void ) const {
    std::cout << "Meowwwwwwwwwww" << std::endl;
}
