/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 02:46:13 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/17 18:00:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
        
    public:
        AMateria(void); // Default constructor
        AMateria(std::string const& type); // Parameterized constructor
        AMateria(const AMateria &other); // Copy constructor
        AMateria& operator=(const AMateria& other); // Copy assignment operator
        virtual ~AMateria(void); // Destructor
        
        std::string const& getType() const; //Returns the materia type
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
        
};

#endif
