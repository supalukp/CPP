/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:22:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/13 11:04:20 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : virtual public Animal 
{
    public:
        Dog(void); // Default constructor
        Dog(const Dog &other); // Copy constructor
		Dog& operator=(const Dog& other);  // Copy assignment operator
        ~Dog(void); // Destructor
        
        void makeSound(void) const ;
    
};

#endif