/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:11:26 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 17:46:40 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    for(int i = 0; i < 100; i++) {
        _ideas[i] = "default";
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    for(int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for(int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
} 

const std::string& Brain::getIdea (int index) const {
    return (_ideas[index]);
}

void Brain::setIdea(int index, const std::string& newIdea) {
    _ideas[index] = newIdea;
}
