/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:40:33 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/27 10:54:50 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
	private:
		std::string _name;
	public:
		Zombie(void);
		Zombie(std::string newName);
		~Zombie();
		void announce( void );
		void setName(std::string);
};

Zombie* zombieHorde( int N, std::string name );

#endif
