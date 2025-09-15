/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:16:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/13 11:02:02 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : virtual public Animal
{
    public:
        Cat(void); // Default constructor
        Cat(const Cat &other); // Copy constructor
		Cat& operator=(const Cat& other); // Copy assignment operator
        ~Cat(void); // Destructor

        void makeSound(void) const ;
    
};

#endif
