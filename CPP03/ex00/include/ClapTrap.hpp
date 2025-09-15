/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:11 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/13 11:04:55 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap 
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints; 
		int _attackDamage; 
		
	public:
		ClapTrap(void); // Default constructor
		ClapTrap(std::string newName); // Parameterized constructor
		ClapTrap(const ClapTrap &other); // Copy constructor
		ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
		~ ClapTrap(void); // Destructor
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif