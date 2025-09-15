/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:25:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 22:16:54 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    _type = "Dog";
    _dogBrain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
    _dogBrain = new Brain(*(other._dogBrain));
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *_dogBrain = *(other._dogBrain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete _dogBrain;
}
        
void Dog::makeSound(void) const  {
    std::cout << "Wolfffffffffff" << std::endl;
}

Brain* Dog::getBrain() {
    return (_dogBrain);
}

const Brain* Dog::getBrain() const {
    return (_dogBrain);
}