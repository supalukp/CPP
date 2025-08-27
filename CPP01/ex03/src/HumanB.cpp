/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:56:26 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/27 11:33:18 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
    : _name(name), _weapon(NULL) 
{
    std::cout << "HumanB created\n";
} 


HumanB::~HumanB ( void )
{
    std::cout << "HumanB destroyed\n";
}

void HumanB::attack( void ) const
{
    if (_weapon) 
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
}

void HumanB::setWeapon( Weapon& newWeapon )
{
    _weapon = &newWeapon;
}
