/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:15:03 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/26 10:49:16 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _inventory[4];
        int _inventoryCount;

    public:
        MateriaSource(void); // Default constructor
        MateriaSource(const MateriaSource &other); // Copy constructor
        MateriaSource& operator=(const MateriaSource &other); // Copy assignment operator
        ~MateriaSource(void); // Destructor
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
