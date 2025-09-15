/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:22:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 17:50:44 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
    private:
        Brain* _dogBrain;
        
    public:
        Dog(void); // Default constructor
        Dog(const Dog &other); // Copy constructor
		Dog& operator=(const Dog& other);  // Copy assignment operator
        ~Dog(void); // Destructor
        
        void makeSound(void) const ;
        Brain* getBrain(void);
        const Brain* getBrain(void) const;
};

#endif