/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:50:44 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 18:55:20 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
    private:
        std::string name;

    public:
        DiamondTrap(void); // Default constructor
        DiamondTrap(const std::string& diamondName); // Parameterized constructor
        DiamondTrap(const DiamondTrap &other); // Copy constructor
		DiamondTrap& operator=(const DiamondTrap& other);  // Copy assignment operator
		~DiamondTrap(void); // Destructor
        
        void whoAmI(void);
};

#endif
