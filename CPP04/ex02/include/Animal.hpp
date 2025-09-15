/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:53:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 21:50:09 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal 
{
    protected:
        std::string _type;
    
    public:
        Animal(void); // Default constructor
        Animal(std::string newType); // Parameterized constructor
        Animal(const Animal &other); // Copy constructor
        Animal& operator=(const Animal& other); // Copy assignment operator
        virtual ~Animal(void); // Destructor
        
        virtual void makeSound(void) const = 0;
        std::string const& getType(void) const; 
        
};

#endif
