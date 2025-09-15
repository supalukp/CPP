/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:48:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 17:34:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(void); // Default constructor
        WrongCat(const WrongCat &other); // Copy constructor
		WrongCat& operator=(const WrongCat& other); // Copy assignment operator
        ~WrongCat(void); // Destructor

        void makeSound(void) const ;
    
};

#endif