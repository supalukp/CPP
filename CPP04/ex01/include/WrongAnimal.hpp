/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:45:47 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 14:01:24 by spunyapr         ###   ########.fr       */
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
        WrongAnimal(void);
        WrongAnimal(std::string newType);
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal(void);
        
        virtual void makeSound(void) const = 0;
        std::string const& getType(void) const; 
        
};

#endif
