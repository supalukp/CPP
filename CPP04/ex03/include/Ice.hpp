/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:15:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/17 09:52:55 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void); // Default constructor
        Ice(const Ice &other); // Copy constructor
		Ice& operator=(const Ice& other); // Copy assignment operator
        ~Ice(void); // Destructor

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
