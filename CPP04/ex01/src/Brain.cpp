/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:16:28 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/07 12:28:23 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
     std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100 ; i++)
        {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain( void ) {
    std::cout << "Brain Destructor called" << std::endl;
}
