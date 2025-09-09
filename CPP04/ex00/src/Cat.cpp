/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:18:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 13:59:48 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    _type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwwwwwwwww" << std::endl;
}
    