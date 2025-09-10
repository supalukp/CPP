/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:11 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/10 15:34:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap 
{
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints; 
		int _attackDamage;
		
	public:
		ClapTrap(void);
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap& other);
		~ ClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
