/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:53:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 22:55:05 by spunyapr         ###   ########.fr       */
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
        Animal(void);
        Animal(std::string newType);
        Animal(const Animal &other);
        Animal& operator=(const Animal& other);
        virtual ~Animal(void);
        
        virtual void makeSound(void) const = 0;
        std::string const& getType(void) const; 
        
};

#endif
