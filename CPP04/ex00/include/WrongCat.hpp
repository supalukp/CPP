/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:48:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/13 11:24:23 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat(void); // Default constructor
        WrongCat(const WrongCat &other); // Copy constructor
		WrongCat& operator=(const WrongCat& other); // Copy assignment operator
        ~WrongCat(void); // Destructor

        void makeSound(void) const ;
    
};

#endif