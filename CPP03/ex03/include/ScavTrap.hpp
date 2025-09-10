/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:43:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/10 15:43:38 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap 
{
        
    public:
        ScavTrap(const std::string& name);
		~ScavTrap(void);
        
        void attack(const std::string& target);
        void guardGate(void);
};

#endif

