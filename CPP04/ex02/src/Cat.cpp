/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 22:17:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    _type = "Cat";
    _catBrain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    _catBrain = new Brain(*(other._catBrain));
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *_catBrain = *(other._catBrain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
    delete _catBrain;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwwwwwwwww" << std::endl;
}

Brain* Cat::getBrain() {
    return (_catBrain);
}

const Brain* Cat::getBrain() const {
    return (_catBrain);
}
