/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:45:47 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 14:14:00 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal 
{
    protected:
        std::string _type;
    
    public:
        WrongAnimal(void); // Default constructor
        WrongAnimal(std::string newType); // Parameterized constructor
        WrongAnimal(const WrongAnimal &other); // Copy constructor
        WrongAnimal& operator=(const WrongAnimal& other); // Copy assignment operator
        virtual ~WrongAnimal(void); // Destructor
        
        void makeSound(void) const;
        std::string const& getType(void) const; 
        
};

#endif
