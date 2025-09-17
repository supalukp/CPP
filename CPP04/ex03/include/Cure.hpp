/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:42:03 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/16 13:42:26 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void); // Default constructor
        Cure(const Cure &other); // Default constructor
		Cure& operator=(const Cure& other); // Copy assignment operator
        ~Cure(void); // Destructor

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif