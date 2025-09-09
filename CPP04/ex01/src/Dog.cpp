/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:25:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 14:02:09 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    _dogBrain = new Brain;
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) 
    : Animal(other), _dogBrain(new Brain(*other._dogBrain)) {
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
        delete this->_dogBrain;
        this->_dogBrain = new Brain(*other._dogBrain);
	}
	return (*this);
}

Dog::~Dog(void) {
    delete _dogBrain;
    std::cout << "Cat Destructor called" << std::endl;
}
        
void Dog::makeSound(void) const  {
    std::cout << "Wolfffffffffff" << std::endl;
}
