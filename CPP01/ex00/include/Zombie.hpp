/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:40:33 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 13:14:30 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie( std::string newName );
		~Zombie( void );
		void announce( void ); 
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
