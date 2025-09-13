/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:43:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 17:39:58 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap 
{
    public:
        ScavTrap(void); // Default constructor
        ScavTrap(const std::string& name); // Parameterized constructor
        ScavTrap(const ScavTrap &other); // Copy constructor
		ScavTrap& operator=(const ScavTrap& other);  // Copy assignment operator
		~ScavTrap(void); // Destuctor
        
        void attack(const std::string& target);
        void guardGate(void);
};

#endif

