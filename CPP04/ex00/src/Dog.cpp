/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:25:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/10 16:13:18 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor called" << std::endl;
}
        
void Dog::makeSound(void) const  {
    std::cout << "Wolfffffffffff" << std::endl;
}
