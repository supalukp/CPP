/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:15:03 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/17 17:20:58 by spunyapr         ###   ########.fr       */
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
        std::string _type;
        AMateria* _inventory[4];
        int _inventoryCount;

    public:
        MateriaSource(void); // Default constructor
        MateriaSource(std::string newType);
        MateriaSource(const MateriaSource &other); // Copy constructor
        MateriaSource& operator=(const MateriaSource &other); // Copy assignment operator
        ~MateriaSource(void); // Destructor
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
