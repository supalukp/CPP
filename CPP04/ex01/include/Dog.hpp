/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:22:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 22:55:26 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal 
{
    private:
        Brain* _dogBrain;
        
    public:
        Dog(void);
        Dog(const Dog &other);
        Dog& operator=(const Dog& other);
        ~Dog(void);
        
        void makeSound(void) const ;
    
};

#endif